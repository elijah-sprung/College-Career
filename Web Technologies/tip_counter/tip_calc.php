<?php
    // get the data from the form
    $after_tax = $_POST['after_tax'];
    $tip_percent = $_POST['tip_percent'];
    
    // calculate the discount
    $tip = $after_tax * $tip_percent * .01;
    $total_price = $after_tax + $tip;
    
    // apply currency formatting to the dollar and percent amounts
    $after_tax_formatted = "$".number_format($after_tax, 2);
    $tip_percent_formatted = $tip_percent."%";
    $tip_formatted = "$".number_format($tip, 2);
    $total_price_formatted = "$".number_format($total_price, 2);            
?>

<!DOCTYPE html>
<html>
    <head>
    <title>Tip Calculator</title>
    <link rel="stylesheet" type="text/css" href="main.css">
    </head>
    <body>
        <main>
            <h1>Product Discount Calculator</h1>

            <label>After Tax:</label>
            <span><?php echo $after_tax_formatted; ?></span><br>

            <label>Tip Percent:</label>
            <span><?php echo $tip_percent_formatted; ?></span><br>

            <label>Total Tip:</label>
            <span><?php echo $tip_formatted; ?></span><br>

            <label>Total Price:</label>
            <span><?php echo $total_price_formatted; ?></span><br>
        </main>
    </body>
</html>