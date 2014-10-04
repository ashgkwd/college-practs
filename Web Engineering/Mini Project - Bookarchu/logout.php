<?php
require('Models/Session.php');

$S = new Session();
$S->end();

header('Location: /#loggedout'.session_id());
die();
