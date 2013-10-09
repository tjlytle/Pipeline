<?php
require_once __DIR__ . '/../bootstrap.php';

header('Content-Type: application/json');

$mongo = new MongoClient(MONGO);
$collection = $mongo->arduino->reports;

$cursor = $collection->find(array('number' => ARDUINO_NUMBER));
$cursor->sort(array('created' => -1))->limit(10);

echo json_encode(iterator_to_array($cursor));