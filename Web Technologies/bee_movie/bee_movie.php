<?php
    $one = filter_input(INPUT_POST, 'one');
    $two = filter_input(INPUT_POST, 'two');
    $three = filter_input(INPUT_POST, 'three');
    $four = filter_input(INPUT_POST, 'four');
    $five = filter_input(INPUT_POST, 'five');
    $six = filter_input(INPUT_POST, 'six');
    $seven = filter_input(INPUT_POST, 'seven');
    $eight = filter_input(INPUT_POST, 'eight');
    $nine = filter_input(INPUT_POST, 'nine');
    $ten = filter_input(INPUT_POST, 'ten');

    $sentence = 'Hello';
?>

<!DOCTYPE html>

<html lang="en" xmlns="http://www.w3.org/1999/xhtml">

<head>
    <meta charset="utf-8" />
    <title>
        Your Movie
    </title>
    <link rel="stylesheet" type="text/css" href="main.css" />
    <style>
        h1 {
            border: 5px solid #FFB121;
            border-radius: 8px;
            margin: 0 auto;
            padding: 2em;
            text-align: center;
            width: 450px;
            }
    </style>
    
</head>

<body>

    <h1>
        According to all known laws of <?php echo htmlspecialchars($one); ?>, there is no way a <?php echo htmlspecialchars($two); ?> should be able to <?php echo htmlspecialchars($three); ?>. <br>

        Its <?php echo htmlspecialchars($four); ?> are too <?php echo htmlspecialchars($five); ?> to get its <?php echo htmlspecialchars($six); ?> little body off of the <?php echo htmlspecialchars($seven); ?>. <br>

        The <?php echo htmlspecialchars($two); ?>, of course, <?php echo htmlspecialchars($eight); ?> anyway because <?php echo htmlspecialchars($two); ?>s don't care what <?php echo htmlspecialchars($nine); ?> think is impossible. <br>

        You like <?php echo htmlspecialchars($ten); ?>?
    </h1>
</body>

<script>
        speechSynthesis.getVoices().forEach(function(voice) {
        console.log(voice.name, voice.default ? voice.default :'');});
        var msg = new SpeechSynthesisUtterance();
        msg.text = document.getElementsByTagName('h1')[0].innerHTML;
        window.speechSynthesis.speak(msg);
        if ('speechSynthesis' in window) {
         // Speech Synthesis supported 
        }else{
         // Speech Synthesis Not Supported 
        alert("Sorry, your browser doesn't support text to speech!");
        }
</script>

<footer>
        <p>
            Copyright &copy;
            <script>document.write(new Date().getFullYear())</script>
            Elijah, Matt, and Connor
        </p>
    </footer>

</html>