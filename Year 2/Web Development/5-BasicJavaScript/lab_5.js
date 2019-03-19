"use strict";

//1.1
document.getElementsByClassName("output1")[0].addEventListener("focus", function(event){
	var inputs = document.querySelectorAll('div.first_task input');
	var x = []
	var y = []
	var i, j;
	j = 0;
	for (i=0; i < inputs.length - 1; i+=2)
	{
		x[j] = inputs[i].value;
		y[j] = inputs[i+1].value;
		j++;
	}
	var l1 = Math.sqrt(Math.pow((x[1]-x[0]),2) + Math.pow((y[1]-y[0]),2));
	var l2 = Math.sqrt(Math.pow((x[2]-x[1]),2) + Math.pow((y[2]-y[1]),2));
	var l3 = Math.sqrt(Math.pow((x[2]-x[0]),2) + Math.pow((y[2]-y[0]),2));
	var halfperimeter = (l1 + l2 + l3) /2;
	var area = Math.sqrt(halfperimeter*(halfperimeter - l1)*(halfperimeter-l2)*(halfperimeter-l3));
	event.target.value = area;
});

//1.2
var text_fields = document.querySelectorAll("div.second_task input");
text_fields.forEach(function(item){
	item.addEventListener("blur", function(event){
		if (event.target.id == "text1") {
			document.getElementById("text2").value = [event.target.value, event.target.value = document.getElementById("text2").value][0];
		} 
		else {
			document.getElementById("text1").value = [event.target.value, event.target.value = document.getElementById("text1").value][0];
		}
	});
});

//1.3
document.getElementById("submit3").addEventListener("click", function(event){
	var input = document.querySelector('div.third_task input').value;
	var numbers = input.split(",");
	var max = Number(numbers[0]);
	var countmax = 0;
	for (var i=1; i < numbers.length; i++)
	{
		if (Number(numbers[i] > max)){
			max = Number(numbers[i]);
		}
	}
	for (var i = 0; i < numbers.length; i++)
	{
		if (Number(numbers[i]) == max)
		{
			countmax++;
		}
	}
	document.querySelector("div.third_task p").innerHTML="Max number: " + max + " Quantity: " + countmax;
});

//1.4
document.getElementById("submit4").addEventListener("click", function(event){
	var inputs = document.querySelectorAll('div.fourth_task input');
	if ((Number(inputs[0].value) + Number(inputs[1].value) <= Number(inputs[2].value)) || (Number(inputs[1].value) + Number(inputs[2].value) <= Number(inputs[0].value)) || (Number(inputs[0].value) + Number(inputs[2].value) <= Number(inputs[1].value))) {
		document.querySelector("div.fourth_task p").innerHTML="<span style='color:red'>Unable to build triangle</span>";
	}
	else {
		document.querySelector("div.fourth_task p").innerHTML="<span style='color:green'>Able to build triangle</span>";
	}
});

//1.5
var hr = document.getElementById("manipulation");
document.getElementById("submit5u").addEventListener("click", function(event){
	hr.style.top = String(Number(getComputedStyle(hr).top.slice(0, getComputedStyle(hr).top.indexOf("p"))) - 10) + "px";
});
document.getElementById("submit5d").addEventListener("click", function(event){
	hr.style.top = String(Number(getComputedStyle(hr).top.slice(0, getComputedStyle(hr).top.indexOf("p"))) + 10) + "px";
});
document.getElementById("submit5l").addEventListener("click", function(event){
	hr.style.left = String(Number(getComputedStyle(hr).left.slice(0, getComputedStyle(hr).left.indexOf("p"))) - 10) + "px";
});
document.getElementById("submit5r").addEventListener("click", function(event){
	hr.style.left = String(Number(getComputedStyle(hr).left.slice(0, getComputedStyle(hr).left.indexOf("p"))) + 10) + "px";
});
document.getElementById("submit5+").addEventListener("click", function(event){
	hr.style.width = String(Number(getComputedStyle(hr).width.slice(0, getComputedStyle(hr).width.indexOf("p"))) + 10) + "px";
});
document.getElementById("submit5-").addEventListener("click", function(event){
	if (Number(getComputedStyle(hr).width.slice(0, getComputedStyle(hr).width.indexOf("p"))) > 9){
		hr.style.width = String(Number(getComputedStyle(hr).width.slice(0, getComputedStyle(hr).width.indexOf("p"))) - 10) + "px";
	}
});

//1.6
var main_select = document.getElementById("table_colour_select");
var colour_table = document.getElementById("colour_table");
main_select.addEventListener("change", function(event){
	colour_table.style.background = main_select.options[main_select.selectedIndex].value;
});
var table_cells = document.querySelectorAll(".colour");
table_cells.forEach(function(item){
	item.addEventListener("change", function(event){
		item.parentElement.style.background = item.options[item.selectedIndex].value;
	});
});

//1.7
var count_lucky = sum_tickets(3);
function sum_tickets(n) {
	var sum_all = 0
	for (var i = 0; i <= 9*n; i++)
	{
		sum_all += Math.pow(count_tickets(n, i),2);
	}
	return sum_all;
}
function count_tickets(n, k){
	if (k < 0)
	{
		return 0;
	}
	if (n==0 && k==0)
	{
		return 1;
	}
	else if (n==0 && k > 0)
	{
		return 0;
	}
	else if (n > 0){
		var sum = 0;
		for (var j = 0; j <= 9; j++)
		{
			sum += count_tickets(n-1, k-j);
		}
		return sum;
	}
}
document.getElementById("task_answer7").innerHTML = count_lucky;

//1.8
document.getElementById("date_select").addEventListener("change", function(event){
	var date = event.target.value.split("-");
	console.log(event.target.value);
	var days = 0;
	for (var i = 0; i < Number(date[1]) - 1; i++)
	{
		if (i==1)
		{
			days+=28;
			console.log(28);
		}
		else if (i%2==0)
		{
			days+=31;
			console.log(31);
		}
		else 
		{
			days+=30;
			console.log(30);
		}
	}
	days += Number(date[2]);
	var week_num = Math.ceil(Number(days)/7);
	document.getElementById("task_answer8").innerHTML = week_num;
});

//1.9
document.getElementById("text_field").addEventListener("change", function(event){
	var words = event.target.value.match(/\S+/g);
	document.getElementById("task_answer9").innerHTML = "Number of words: " + words.length;
});	

//1.10
document.addEventListener("DOMContentLoaded", async function(event){
	var image = document.getElementById("anim");
	var i = 1;
	var image_arr = [];
	for (var j = 1; j < 9; j++)
	{
		image_arr[j] = String(j) + ".jpg";
	}
	setInterval(function(){
		image.setAttribute("src", image_arr[i]);
		i++;
		if (i > 8){
			i=1;
		}
	}, 2000);
});

//1.11
document.getElementById("submit11").addEventListener("click", function(event){
	var email_input = document.getElementById("email_input").value;
	var reply = document.getElementById("task_answer11");
	var first_part = email_input.slice(0, email_input.indexOf("@"));
	var second_part = email_input.slice(email_input.indexOf("@"), email_input.length - 1);
	if (email_input.length < 5)
	{
		reply.innerHTML = "<span style='color:red'>String is too short to be an email</span>";
	}
	else if (email_input.indexOf("@") == 1 || email_input.indexOf("@") == email_input.length || email_input.replace(/[^@]/g, "").length > 1 || email_input.indexOf(" ") != -1 || second_part.replace(/[^.]/g, "").length > 1 || second_part.replace(/[^.]/g, "").length < 1)
	{
		reply.innerHTML = "<span style='color:red'>Please input valid email address</span>";
	}
	else 
	{
		reply.innerHTML = "<span style='color:green'>Email address is valid</span>";
	}
})