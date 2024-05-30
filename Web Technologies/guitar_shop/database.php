<?php
    $dsn = 'mysql:host=joecool.highpoint.edu;dbname=CSC3212_S22_esprung_db';
    $username = 'esprungweb';
    $password = '!&(*&!(';

    try {
        $db = new PDO($dsn, $username, $password);
    } catch (PDOException $e) {
        $error_message = $e->getMessage();
        include('database_error.php');
        exit();
    }
?>