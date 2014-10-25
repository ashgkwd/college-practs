<?php
require_once('Database.php');

class Session
{
  private $status = null;
  function __construct() {
    session_start();
    if (!empty($_SESSION['admin']) and $_SESSION['admin'] == 'admin')
      $this->status = session_id();
  }

  function start() {
    session_start();
    $_SESSION['admin'] = 'admin';
  }

  function end() {
    $_SESSION = array();
    session_destroy();
    setcookie('PHPSESSID', '', time() - 60);
  }

  function isLoggedIn() {
    return !empty($_SESSION['admin']) and $_SESSION['admin'] == 'admin';
  }
}