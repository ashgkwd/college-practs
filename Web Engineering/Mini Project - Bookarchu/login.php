<?php
if (empty($_POST['password']) or empty($_POST['email'])) {
  header('Location: /index.php?login=true');
  die();
}

require('Models/Session.php');

if ($_POST['email']=="admin@bookarchu.com" and md5($_POST['password'])==md5("bookarchu")) {
  // lets start session
  // use default php session
  $S = new Session();
  $S->start();

  header('Location: /#loggedin');
} else {
  header('Location: /index.php?login=true&attempt=1');
}