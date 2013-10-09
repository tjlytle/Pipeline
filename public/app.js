google.load('visualization', '1.0', {'packages':['corechart']});

// Set a callback to run when the Google Visualization API is loaded.
google.setOnLoadCallback(drawChart);

// Callback that creates and populates a data table,
// instantiates the pie chart, passes in the data and
// draws it.
var arduinoData = [
    ['Report', 'Light', 'Temp'],
];

function drawChart() {
    var data = google.visualization.arrayToDataTable(arduinoData);

    var options = {};

    var chart = new google.visualization.BarChart(document.getElementById('chart_div'));
    chart.draw(data, options);
}

function DataStuff($scope, $http) {
    function update(){
      $http.get('../data.php').success(function(data) {
        $scope.data = data;

        arduinoData = [
          ['Report', 'Light', 'Temp'],
        ];

        angular.forEach(data, function(report){
          arduinoData.push(['', +report.light, +report.temp]);
          console.log(report);
        });

        drawChart();

      });
      
      setTimeout(update, 500);
  }
  update();
};
