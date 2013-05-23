<?php
header('Content-Type: application/json');
$db = fopen('data.csv', 'r');
while($row = fgetcsv($db)){
    if($row[1] !== '17739684150'){
        continue;
    }
    
    //convert to percentage
    $row[0] = ($row[0]/255)*100 . '%';
    $data[] = array_combine(array('value', 'number', 'time'), $row);
}

//just give last 10
$data = array_reverse($data);
$data = array_slice($data, 0,10);
echo json_encode($data);
fclose($db);
