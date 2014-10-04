<?php
/** MySql Query To Create Database, Tables, users

CREATE DATABASE bookarchu;

USE bookarchu;

CREATE USER 'spiderman'@'localhost' IDENTIFIED BY 'gwenstacy';

GRANT ALL PRIVILEGES ON bookarchu.* TO 'spiderman'@'localhost';

FLUSH PRIVILAGES;

CREATE TABLE books (
  `id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  title varchar (255) NOT NULL,
  author varchar (255) NOT NULL,
  publication varchar (255) NOT NULL,
  download varchar (700) NOT NULL
)ENGINE=InnoDB;
**/

class DB
{
  private $class_id = 1;
  public $conn = null;
  function __construct()
  {
    $this->conn = new PDO('mysql:host=localhost;dbname=bookarchu;charset=utf8', 'spiderman', 'gwenstacy');
  }

  function q($query)
  {
    return $this->conn->query($query)->fetchAll(PDO::FETCH_ASSOC);
  }

  function getConn()
  {
    return $this->conn;
  }
}
