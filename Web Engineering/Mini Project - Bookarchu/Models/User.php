<?php
require('Database.php');

class User
{
  // simply provides information of user
  private const $class_id = 3;
  private $current = null;
  private $db = null;
  private $conn = null;

  function __construct()
  {
    require('Session.php');
    $S = new Session();
    if ($S->isLoggedin()) {
      $this->current = $_COOKIE['id'];

      $db = new DB();
      $this->db = $db;
      $this->conn = $db->getConn();

      if ($S->isAdmin()){
        $this->type = "admin";
      } else {
        $this->type = "user";
      }
    } else {
      throw new Exception("Not loggedin exception", $this->class_id);
    }
  }

  function info()
  {
    return $this->db->q("SELECT name, type, id FROM  users WHERE id = {$this->current}");
  }
}