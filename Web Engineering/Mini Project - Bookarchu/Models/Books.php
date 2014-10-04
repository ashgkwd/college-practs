<?php
require_once('Database.php');

class Books
{
  // handle add, remove, modify operations on book. Admin access is required
  private $class_id = 4;

  function __construct() {
    require_once('Session.php');
    $S = new Session;
    if (!$S->isLoggedIn()) {
      throw new Exception("Admin access required", $this->class_id);
    }
  }

  function add ($D) {
    if (empty($D['title']) or empty($D['download']) or empty($D['publication']) or empty($D['author'])) return ['status'=>'fail'];
    $db = new DB;
    $S = $db->getConn()->prepare('INSERT INTO books (title, author, publication, download) VALUES(:t, :a, :p, :d)');
    if ($S->execute([':t'=>$D['title'], ':a'=>$D['author'], ':p'=>$D['publication'], ':d'=>$D['download']]))
      return ['status'=>'success'];
    return ['status'=>'fail'];
  }

  function remove ($id) {
    if (empty($id)) return ['status'=>'fail'];
    $db = new DB;
    $S = $db->getConn()->prepare("DELETE FROM books WHERE id = :id");
    return ['status'=> ($S->execute([':id'=>$id]))? 'success': 'fail'];
  }
}