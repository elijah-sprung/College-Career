<?php
// Get the product data
$fname = filter_input(INPUT_POST, 'firstname');
$lname = filter_input(INPUT_POST, 'lastname');
$number = filter_input(INPUT_POST, 'phonenumber', FILTER_VALIDATE_INT);
$home_state = filter_input(INPUT_POST, 'state');
$message = filter_input(INPUT_POST, 'subject');

// Validate inputs
if ($fname == null || $lname == false ||
        $number == null || $home_state == null || $message == null) {
    $error = "Invalid product data. Check all fields and try again.";
    include('error.php');
} else {
    require_once('database.php');

    // Add the product to the database  
    $query = 'INSERT INTO mailing_list
                 (fname, lname, num, home_state, message)
              VALUES
                 (:firstname, :lastname, :phonenumber, :state, :subject)';
    $statement = $db->prepare($query);
    $statement->bindValue(':firstname', $fname);
    $statement->bindValue(':lastname', $lname);
    $statement->bindValue(':phonenumber', $number);
    $statement->bindValue(':state', $home_state);
    $statement->bindValue(':subject', $message);
    $statement->execute();
    $statement->closeCursor();

    // Display the Product List page
    include('index.html');
}
?>