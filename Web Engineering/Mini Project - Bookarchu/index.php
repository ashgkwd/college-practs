<?php
require_once('Models/Session.php');

$S = new Session();

if ($S->isLoggedIn()) {
  readfile('Part/AdminHead.html');
  readfile('Part/Search.html');
} else {
  readfile('Part/PublicHead.html');
  if (!empty($_GET['login'])) {
    readfile('Part/LoginForm.html');
  } else {
    readfile('Part/Search.html');
  }
}
