#ifndef PARSER_H_
#define PARSER_H_

#include "symbol.h"
#include "token.h"
#include "scanner.h"
#include "id_table.h"
#include "error_handler.h"

using namespace std;

class parser
{
	public:

		parser(scanner *s, id_table *id_t, error_handler *e);
		void token_dump();

		void program();
		void block();
		void declare();

		void type();
		void parameter_list();
		void parameter();
		void id_list();
		void parameter_kind();

		void statement_list();
		void statement();
		void simple_statement();
		void compound_statement();

		void if_statement();
		void while_statement();
		void for_statement();
		void loop_statement();

		void range();
		void expression();
		void simple_expression();
		void follow_expression();
		void term();
		void factor();
		void primary();

		bool is_number(symbol::symbol_type sym);
		bool is_bool(symbol::symbol_type sym);

		bool is_relop(symbol::symbol_type sym);
		bool is_addop(symbol::symbol_type sym);
		bool is_multop(symbol::symbol_type sym);

		bool first_declaration(symbol::symbol_type sym);
		bool first_statement(symbol::symbol_type sym);
		bool first_simple_statement(symbol::symbol_type sym);
		bool first_compound_statement(symbol::symbol_type sym);
		bool first_expression(symbol::symbol_type sym);

	private:

		bool debugging = false;
		int indentation;

		scanner *s;
		id_table *id_t;
		error_handler *e;
};

#endif
