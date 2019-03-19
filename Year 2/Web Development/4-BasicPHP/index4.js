$(document).ready(function(){
	//2.1
	$("table#first > tbody > tr > td[rowspan]").html("<p style='color:red'>Some text in p</p>");
	$("table#first > tbody > tr > td[colspan]").html("<p>Some text in p</p>");

	//2.2
	$("table#third > tbody > tr > td").html("<div>Some text in div</div>");
	$("table#third > tbody > tr:gt(2)").css("text-transform","uppercase");

	//2.3
	$("table#fourth > tbody > tr:nth-child(1) > td").html("<pre style='overflow:auto'>Some text in pre</pre>");
	$("table#fourth > tbody > tr:nth-child(1) > td:nth-child(3)").append("<hr>");

	//2.4
	$("table#fourth > tbody > tr:nth-last-child(1) > td:nth-child(1)").html("<ul><li>1 рядок</li><li>2 рядок</li><li>3 рядок</li></ul>");
	$("table#fourth > tbody > tr:nth-last-child(1) > td:nth-child(1) > ul > li").each(function(){
		alert($(this).text());
	});
});