<?php
require_once __DIR__ . '/../bootstrap.php';

//use get or post
$request = array_merge($_GET, $_POST);

//check it's from nexmo
if(!isset($request['text']) OR !isset($request['msisdn'])){
    return;
}

//throw the data in a mongo collection
$mongo = new MongoClient(MONGO);
$collection = $mongo->arduino->reports;

list($light, $temp) = preg_split('/\s/', $request['text'], 2);

$collection->insert(array(
    'created' => new MongoDate(),
    'number'  => $request['msisdn'],
    'light'   => $light,
    'temp'    => $temp
));
