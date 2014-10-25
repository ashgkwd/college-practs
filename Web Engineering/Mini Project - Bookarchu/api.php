<?php
$sanitize = function($val) {
  return preg_replace("/[^a-z0-9\s\+\-]+/i", "", strtolower(trim($val)));
};

$D = $_POST;
$backup = (!empty($D['download']))? $D['download']: null;
array_map($sanitize, $D);
$D['download'] = $backup;

if (!empty($D['action'])) {
  switch ($D['action']) {
    // Search related api
    case 'search':
      require_once('Models/Search.php');
      $S = new Search();
      echo json_encode($S->q($D['query']));
      break;

    // BookIssue related api
    /*case 'issue':
      require_once('Models/BookIssue.php');
      $S = new BookIssue();
      echo json_encode($S->issue($D['id']));
      break;

    case 'unissue':
      require_once('Models/BookIssue.php');
      $S = new BookIssue();
      echo json_encode($S->unissue($D['id']));
      break;

    case 'issued':
      require_once('Models/BookIssue.php');
      $S = new BookIssue();
      echo json_encode($S->issued());
      break;*/

    // Books related api
    case 'add':
      require_once('Models/Books.php');
      $S = new Books();
      echo json_encode($S->add($D));
      break;

    case 'remove':
      require_once('Models/Books.php');
      $S = new Books();
      echo json_encode($S->remove($D['bookid']));
      break;

    case 'update':
      require_once('Models/Books.php');
      $S = new Books();
      echo json_encode($S->update($D['id'], $D));
      break;

    // User related api
    /*case 'info':
      require_once('Models/User.php');
      $S = new User();
      echo json_encode($S->info());
      break;*/

    default:
      # Wrong action.
      echo json_encode(['error'=>"Unknown action"]);
      break;
  }
} else {
  echo json_encode(['error'=>"Action is not specified"]);
}