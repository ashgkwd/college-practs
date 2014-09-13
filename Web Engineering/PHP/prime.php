<!doctype html>
<html>
<head>
<title>Prime Numbers</title>
</head>
<body>

<?php
$a = $_GET['a'];
$b = $_GET['b'];
if(is_numeric($a) && is_numeric($b)) {
 function IsPrime($number) {
    if ($number <= 1) return 0; // zero and one are not prime
    if (($number > 2) && (($number % 2) == 0)) return 0; //no even number is prime number (bar 2)
    for ($i=2; $i*$i<=$number; $i++) {
      if ($number % $i == 0) return 0;
    }
    return 1;
  }

  function PrintPrime($a, $b) {
   $primes = array();
   for($i=$a; $i < $b; $i++) {
     if(IsPrime($i)) $primes[] = $i;
   }
   return $primes;
 }
?>
<div>
  <h1>Prime Numbers Between <?php echo $a; ?> and <?php echo $b; ?></h1>
  <ul>
    <?php echo "<li>" . implode("</li><li>", PrintPrime($a, $b)) . "</li>"; ?>
  </ul>
</div>
</body>
</html>

<?php
  } else {
?>

<div>
  <h1>Provide Two Integers</h1>
  <p>This program will find all the prime numbers between these numbers</p>

  <form action="/prime.php" method="get">
  <dl>
    <dt>First Number</dt>
    <dd> <input type="number" name="a"> </dd>
    <dt>Second Number</dt>
    <dd> <input type="number" name="b"> </dd>
  </dl>
  <p> <input type="submit" value="List Primes!"> </p>
  </form>
</div>

<?php } ?>
</body>
</html>