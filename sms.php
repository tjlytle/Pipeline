<?php
//look valid?
if(!isset($_POST['text']) OR !isset($_POST['msisdn'])){
    return;
}

//throw it in a csv file (poor man's database)
$db = fopen('data.csv', 'a');
$data = array($_POST['text'], $_POST['msisdn'], time());
fputcsv($db, $data);
fclose($db);
