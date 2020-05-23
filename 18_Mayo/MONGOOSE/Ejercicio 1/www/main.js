$(document).ready(function() {
	$("#response").html("<img src='load.gif' width=50/>");
    var ctx = document.getElementById('myChart');
    var chart = new Chart(ctx, {
        type: 'bar',
        data: {
            labels: [],
            datasets : [{
                label: "#Votos",
                data: [],
                backgroundColor: [
                    'rgba(255, 99, 132, 0.2)',
                    'rgba(54, 162, 235, 0.2)',
                    'rgba(255, 206, 86, 0.2)',
                    'rgba(75, 192, 192, 0.2)',
                    'rgba(153, 102, 255, 0.2)',
                    'rgba(255, 159, 64, 0.2)'
                ], borderColor: [
                    'rgba(255, 99, 132, 1)',
                    'rgba(54, 162, 235, 1)',
                    'rgba(255, 206, 86, 1)',
                    'rgba(75, 192, 192, 1)',
                    'rgba(153, 102, 255, 1)',
                    'rgba(255, 159, 64, 1)'
                ],
                borderWidth: 1 
            }] 
        },
        options: {
            title: {
                display: true,
                text: "Votos por servidor"
            },
            animation: {
                animateRotate: true
            },
            tooltips: {
                mode: 'index',
                intersect: false
            }
        }
    });
  // Start 1-second timer to call RESTful endpoint
  setInterval(function(){
	$.ajax({
		type: "GET",
		url: "/managment",
		success: function(data){
			array_data = data.split(' ');
			array_data.slice(0, 1,  "");
			array_data.pop();
			array_labels = array_data.map(function(x){
				return x.split(';')[0];
			});
			array_data = array_data.map(function(x){
				return x.split(';')[1];
			});
            $("#response").html(data);
            chart.data.labels = array_labels;
            chart.data.datasets[0].data = array_data;
            chart.update();
		}
	});
  }, 1000);  
});

