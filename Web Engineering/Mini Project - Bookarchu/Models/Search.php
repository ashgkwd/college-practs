<?php
require('Database.php');

class Search
{
  private $class_id = 2;
  private $conn = null;

  function __construct() {
    $db = new DB();
    $this->conn = $db->getConn();
  }

  function q($text)
  {
    if (empty($text)) return;
    $S = $this->conn->prepare("SELECT * FROM books WHERE title LIKE :text OR author LIKE :text OR publication LIKE :text");
    $S->execute([':text'=>"%".$text."%"]);
    return $S->fetchAll(PDO::FETCH_ASSOC);
  }
}
