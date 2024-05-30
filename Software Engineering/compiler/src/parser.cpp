#include "scanner.h"
#include "id_table.h"
#include "error_handler.h"
#include "parser.h"

parser::parser(scanner *s_, id_table *id_t_, error_handler *e_)
{
	indentation = -1;

	s = s_;
	id_t = id_t_;
	e = e_;
}

void parser::token_dump()
{
	token *t;

	do
	{
		t = s->get_token();
		t->print_token();
	}
	while (t->get_sym() != symbol::end_of_program);
}

void parser::program()
{
	s->get_token();
	s->must_be(symbol::program_sym);
	s->must_be(symbol::identifier);
	s->must_be(symbol::is_sym);

	block();

	s->must_be(symbol::semicolon_sym);

	if (s->have(symbol::end_of_program))
	{
		s->must_be(symbol::end_of_program);
	}
	else
	{
		e->flag(s->this_token(), 77);
	}
}

void parser::block()
{
	while (first_declaration(s->this_token()->get_sym()))
	{
		declare();
	}

	s->must_be(symbol::begin_sym);

	statement_list();

	s->must_be(symbol::end_sym);

	if (s->have(symbol::identifier))
	{
		s->must_be(symbol::identifier);
	}
}

void parser::declare()
{
	if(s->have(symbol::identifier))
	{
		id_list();

		s->must_be(symbol::colon_sym);

		if (s->have(symbol::constant_sym))
		{
			s->must_be(symbol::constant_sym);
		}

		type();

		if (s->have(symbol::becomes_sym))
		{
			s->must_be(symbol::becomes_sym);

			if ((s->have(symbol::integer)) || (s->have(symbol::real_num)) || (s->have(symbol::strng)) || (s->have(symbol::true_sym)) || (s->have(symbol::false_sym)))
			{
				s->get_token();
			}
			else
			{
				e->flag(s->this_token(), 84);
			}
		}

		s->must_be(symbol::semicolon_sym);
	}
	else if (s->have(symbol::procedure_sym))
	{
		s->must_be(symbol::procedure_sym);
		s->must_be(symbol::identifier);

		if (s->have(symbol::left_paren_sym))
		{
			s->must_be(symbol::left_paren_sym);

			parameter_list();

			s->must_be(symbol::right_paren_sym);
		}

		s->must_be(symbol::is_sym);

		block();

		s->must_be(symbol::semicolon_sym);
	}
	else if (s->have(symbol::function_sym))
	{
		s->must_be(symbol::function_sym);
		s->must_be(symbol::identifier);

		if (s->have(symbol::left_paren_sym))
		{
			s->must_be(symbol::left_paren_sym);

			parameter_list();

			s->must_be(symbol::right_paren_sym);
		}

		s->must_be(symbol::return_sym);

		type();

		s->must_be(symbol::is_sym);

		block();

		s->must_be(symbol::semicolon_sym);
	}
	else
	{
		e->flag(s->this_token(), 106);
	}
}

void parser::type()
{
	if ((s->have(symbol::integer_sym)) || (s->have(symbol::real_sym)) || (s->have(symbol::string_sym)) || (s->have(symbol::boolean_sym)))
	{
		s->get_token();
	}
	else
	{
		e->flag(s->this_token(), 96);
	}
}

void parser::parameter_list()
{
	parameter();

	while (s->have(symbol::semicolon_sym))
	{
		s->must_be(symbol::semicolon_sym);

		parameter();
	}

	if (!(s->have(symbol::right_paren_sym)))
	{
		e->flag(s->this_token(), 95);
	}
}

void parser::parameter()
{
	id_list();

	s->must_be(symbol::colon_sym);

	parameter_kind();

	type();
}

void parser::id_list()
{
	s->must_be(symbol::identifier);

	while (s->have(symbol::comma_sym))
	{
		s->must_be(symbol::comma_sym);
		s->must_be(symbol::identifier);
	}
}

void parser::parameter_kind()
{
	if ((s->have(symbol::value_sym)) || (s->have(symbol::ref_sym)))
	{
		s->get_token();
	}
	else
	{
		e->flag(s->this_token(), 94);
	}
}

void parser::statement_list()
{
	statement();

	s->must_be(symbol::semicolon_sym);

	while (first_statement(s->this_token()->get_sym()))
	{
		statement();

		s->must_be(symbol::semicolon_sym);
	}
}

void parser::statement()
{
	if (first_simple_statement(s->this_token()->get_sym()))
	{
		simple_statement();
	}
	else if (first_compound_statement(s->this_token()->get_sym()))
	{
		compound_statement();
	}
	else
	{
		e->flag(s->this_token(), 80);
	}
}

void parser::simple_statement()
{
	if (s->have(symbol::identifier))
	{
		s->must_be(symbol::identifier);

		if (s->have(symbol::left_paren_sym))
		{
			s->must_be(symbol::left_paren_sym);

			if (first_expression(s->this_token()->get_sym()))
			{
				expression();

    				while (s->have(symbol::comma_sym))
    				{
        				s->must_be(symbol::comma_sym);

        				expression();
    				}
			}

			s->must_be(symbol::right_paren_sym);
		}
		else if (s->have(symbol::becomes_sym))
		{
			s->must_be(symbol::becomes_sym);

			expression();
		}
	}
	else if (s->have(symbol::exit_sym))
	{
		s->must_be(symbol::exit_sym);

		if (s->have(symbol::when_sym))
		{
			s->must_be(symbol::when_sym);

			expression();
		}
	}
	else if (s->have(symbol::return_sym))
	{
		s->must_be(symbol::return_sym);

		if (first_expression(s->this_token()->get_sym()))
		{
			expression();
		}
	}
	else if (s->have(symbol::read_sym))
	{
		s->must_be(symbol::read_sym);

		if (s->have(symbol::left_paren_sym))
		{
			s->must_be(symbol::left_paren_sym);

			id_list();

			s->must_be(symbol::right_paren_sym);
		}
		else
		{
			id_list();
		}
	}
	else if (s->have(symbol::write_sym))
	{
		s->must_be(symbol::write_sym);

		if (s->have(symbol::left_paren_sym))
		{
			s->must_be(symbol::left_paren_sym);

			expression();

    			while (s->have(symbol::comma_sym))
    			{
        			s->must_be(symbol::comma_sym);

        			expression();
    			}

			s->must_be(symbol::right_paren_sym);
		}
		else
		{
			expression();

    			while (s->have(symbol::comma_sym))
    			{
        			s->must_be(symbol::comma_sym);

        			expression();
    			}
		}
	}
	else if (s->have(symbol::writeln_sym))
	{
		s->must_be(symbol::writeln_sym);

		if (s->have(symbol::left_paren_sym))
		{
			s->must_be(symbol::left_paren_sym);

			if (first_expression(s->this_token()->get_sym()))
			{
				expression();

    				while (s->have(symbol::comma_sym))
    				{
        				s->must_be(symbol::comma_sym);

        				expression();
    				}
			}

			s->must_be(symbol::right_paren_sym);
		}
		else
		{
			if (first_expression(s->this_token()->get_sym()))
			{
				expression();

    				while (s->have(symbol::comma_sym))
    				{
        				s->must_be(symbol::comma_sym);

        				expression();
    				}
			}

			if (s->have(symbol::right_paren_sym))
			{
				e->flag(s->this_token(), 125);
			}
		}
	}
	else if (s->have(symbol::null_sym))
	{
		s->must_be(symbol::null_sym);
	}
	else
	{
		e->flag(s->this_token(), 83);
	}
}

void parser::compound_statement()
{
	if (s->have(symbol::if_sym))
	{
		if_statement();
	}
	else if (s->have(symbol::while_sym))
	{
		while_statement();
	}
	else if (s->have(symbol::for_sym))
	{
		for_statement();
	}
	else if (s->have(symbol::loop_sym))
	{
		loop_statement();
	}
	else
	{
		e->flag(s->this_token(), 101);
	}
}

void parser::if_statement()
{
	s->must_be(symbol::if_sym);

	expression();

	s->must_be(symbol::then_sym);

	statement_list();

	while (s->have(symbol::elsif_sym))
	{
		s->must_be(symbol::elsif_sym);

		expression();

		s->must_be(symbol::then_sym);

		statement_list();
	}

	if (s->have(symbol::else_sym))
	{
		s->must_be(symbol::else_sym);

		statement_list();
	}

	s->must_be(symbol::end_sym);
	s->must_be(symbol::if_sym);
}

void parser::while_statement()
{
	s->must_be(symbol::while_sym);

	expression();

	loop_statement();
}

void parser::for_statement()
{
	s->must_be(symbol::for_sym);
	s->must_be(symbol::identifier);
	s->must_be(symbol::in_sym);

	if (s->have(symbol::reverse_sym))
	{
		s->must_be(symbol::reverse_sym);
	}

	range();

	loop_statement();
}

void parser::loop_statement()
{
	s->must_be(symbol::loop_sym);

	statement_list();

	s->must_be(symbol::end_sym);
	s->must_be(symbol::loop_sym);
}

void parser::range()
{
	simple_expression();

	s->must_be(symbol::range_sym);

	simple_expression();
}

void parser::expression()
{
	simple_expression();

	if (is_relop(s->this_token()->get_sym()))
	{
		s->get_token();

		simple_expression();
	}
	else if (s->have(symbol::in_sym))
	{
		s->must_be(symbol::in_sym);

		range();
	}
}

void parser::simple_expression()
{
	follow_expression();

	while (s->have(symbol::ampersand_sym))
	{
		s->must_be(symbol::ampersand_sym);

		follow_expression();
	}
}

void parser::follow_expression()
{
	term();

	while ((is_addop(s->this_token()->get_sym())) || (s->have(symbol::or_sym)))
	{
		s->get_token();

		term();
	}
}

void parser::term()
{
	factor();

	while ((is_multop(s->this_token()->get_sym())) || (s->have(symbol::and_sym)))
	{
		s->get_token();

		factor();
	}
}

void parser::factor()
{
	if (is_addop(s->this_token()->get_sym()))
	{
		s->get_token();

		primary();
	}
	else
	{
		primary();

		if (s->have(symbol::power_sym))
		{
			s->must_be(symbol::power_sym);

			primary();
		}
	}
}

void parser::primary()
{
	if (s->have(symbol::not_sym))
	{
		s->must_be(symbol::not_sym);

		expression();
	}
	else if (s->have(symbol::odd_sym))
	{
		s->must_be(symbol::odd_sym);

		expression();
	}
	else if (s->have(symbol::left_paren_sym))
	{
		s->must_be(symbol::left_paren_sym);

		simple_expression();

		s->must_be(symbol::right_paren_sym);
	}
	else if (s->have(symbol::identifier))
	{
		s->must_be(symbol::identifier);

		if (s->have(symbol::left_paren_sym))
		{
			s->must_be(symbol::left_paren_sym);

			expression();

    			while (s->have(symbol::comma_sym))
    			{
        			s->must_be(symbol::comma_sym);

        			expression();
    			}

			s->must_be(symbol::right_paren_sym);
		}
	}
	else if (is_number(s->this_token()->get_sym()))
	{
		s->get_token();
	}
	else if (s->have(symbol::strng))
	{
		s->must_be(symbol::strng);
	}
	else if (is_bool(s->this_token()->get_sym()))
	{
		s->get_token();
	}
	else
	{
		e->flag(s->this_token(), 124);
	}
}

bool parser::is_bool(symbol::symbol_type sym)
{
	return ((s->have(symbol::true_sym)) || (s->have(symbol::false_sym)));
}

bool parser::is_number(symbol::symbol_type sym)
{
	return ((s->have(symbol::integer)) || (s->have(symbol::real_num)));
}

bool parser::is_addop(symbol::symbol_type sym)
{
	return ((s->have(symbol::plus_sym)) || (s->have(symbol::minus_sym)));
}

bool parser::is_multop(symbol::symbol_type sym)
{
	return ((s->have(symbol::asterisk_sym)) || (s->have(symbol::slash_sym)));
}

bool parser::is_relop(symbol::symbol_type sym)
{
	return ((s->have(symbol::greater_than_sym)) || (s->have(symbol::less_than_sym)) || (s->have(symbol::equals_sym)) || (s->have(symbol::not_equals_sym)) || (s->have(symbol::greater_or_equal_sym)) || (s->have(symbol::less_or_equal_sym)));
}

bool parser::first_declaration(symbol::symbol_type sym)
{
	return ((s->have(symbol::identifier)) || (s->have(symbol::procedure_sym)) || (s->have(symbol::function_sym)));
}

bool parser::first_statement(symbol::symbol_type sym)
{
	return (first_simple_statement(sym) || first_compound_statement(sym));
}

bool parser::first_simple_statement(symbol::symbol_type sym)
{
	return ((s->have(symbol::identifier)) || (s->have(symbol::exit_sym)) || (s->have(symbol::return_sym)) || (s->have(symbol::read_sym)) || (s->have(symbol::write_sym)) || (s->have(symbol::writeln_sym)) || (s->have(symbol::null_sym)));
}

bool parser::first_compound_statement(symbol::symbol_type sym)
{
	return ((s->have(symbol::if_sym)) || (s->have(symbol::loop_sym)) || (s->have(symbol::for_sym)) || (s->have(symbol::while_sym)));
}

bool parser::first_expression(symbol::symbol_type sym)
{
	return ((s->have(symbol::not_sym)) || (s->have(symbol::odd_sym)) || (s->have(symbol::left_paren_sym)) || (s->have(symbol::identifier)) || (is_number(s->this_token()->get_sym())) || (s->have(symbol::strng)) || (is_bool(s->this_token()->get_sym())));
}
