<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
	<link rel="stylesheet" type="text/css" href="index.css">
</head>
<body>
	<?php
		if ($_POST["n"] && $_POST["n"] < 1000 && $_POST["n"] > 0) {
			$n = $_POST["n"];
			$db_valid = mysqli_connect("test.ua", "root", "", "valid");
			$query = "INSERT INTO inputs (value) VALUES (".(int)$_POST["n"].")";
			mysqli_query($db_valid, $query);
		}
		else if ($_POST["n"] && ($_POST["n"] > 1000 || $_POST["n"] < 1)) {
			$db_invalid = mysqli_connect("test.ua", "root", "", "invalid");
			$query = "INSERT INTO inputs (value) VALUES (".$_POST["n"].")";
			mysqli_query($db_invalid, $query);
			echo '<div style="text-align: center"><div class="alert">Please, suggest a number in the range from 1 to 999</div></div>';
			$n = 7;
		}
		else {
			$n = 7;
		} 
	?>
	<div style="text-align: center">
		<form action="index.php" method="post">
			Enter the constant for generating tables:<br>
			<input type="number" name="n" required><br>
			<input type="submit" value="Submit">
		</form>
	</div>
	<table id="first">
		<caption>Table 1</caption>
		<?php
			$counter=0;
			for ($i=0; $i<$n; $i++)
			{
				echo '<tr>';
				if ($i > 0) {
					echo '<td rowspan="'.($n-$i).'">';
					if ($counter % 4 == 0) {
						echo '4th cell';
					}
					echo '</td>';
				}
				$counter++;
				echo '<td colspan="'.($n-$i).'"></td>';
				$counter++;
				echo '</tr>';
			}
		?>
	</table><br>
	<table id="second">
		<caption>Table 2</caption>
		<?php
			$counter=1;
			for ($i=0; $i<$n; $i++)
			{
				echo '<tr>';
				echo '<td rowspan="'.($n-$i).'"></td>';
				$counter++;
				if ($i != $n-1) {
					echo '<td colspan="'.($n-$i).'">';
					if ($counter % 4 == 0) {
						echo '4th cell';
					}
					echo '</td>';
				}
				$counter++;
				echo '</tr>';
			}
		?>
	</table><br>
	<table id="third">
		<caption>Table 3</caption>
		<?php
			for ($i=0;$i<$n;$i++)
			{
				echo '<col width="100px">';
			}
			$counter=1;
			$remainder = $n;
			for ($i = 0;$i<$n;$i++)
			{
				echo '<tr>';
				$j=0;
				while ($remainder > 0) 
				{
					if ($remainder >= 2)
					{
						echo '<td colspan="2">';
						$j=$j+2;
					}
					else 
					{
						echo '<td colspan="'.$remainder.'">';
						if ($j==0) {
							$j=$j+$remainder;
						}
						else {
							$j=$j+2;
						}
					}
					if ($counter % 4 == 0) {
						echo '4th cell';
					}
					echo '</td>';
					$counter++;
					$remainder = $n - $j;
				}
				echo '</tr>';
				$remainder = 0 - $remainder;
				if ($remainder == 0) {
					$remainder = 2;
				}
			}
		?>
	</table>
	<table id="fourth">
		<caption>Table 4</caption>
		<?php
			$column_fill=[3,0,0];
			$counter=1;
			$remainder = $n >= 3 ? 3: $n;
			if ($n%3==0 && $n > 3)
			{
				for ($i = 0; $i < $n/3; $i++) 
				{
					echo '<tr style="height:'.(28*($n/3)).'px">';
					for ($j=0; $j < $n; $j++)
					{
						echo '<td>';
						if ($counter % 4 == 0) {
							echo '4th cell';
						}
						$counter++;
						echo '</td>';
					}
					echo '</tr>';
				}
			}
			else 
			{
				echo '<tr style="height: 28px">';
				echo '<td rowspan="'.($n >= 3 ? 3: $n).'">';
				$counter++;
				for ($i = 0; $i < $n - 1; $i++)
				{
					if (0 < $i && $i < 3) 
					{
						$column_fill[$remainder] = $i + 1;
					}
					$fullness = $remainder;
					while ($fullness < $n - 3) {
						$fullness = $fullness + 3;
					}
					$remainder = 3 - ($n - $fullness);
					if ($remainder == 0) {
						$remainder = 3;
					}
					echo '<td rowspan="'.$remainder.'">';
					if ($counter % 4 == 0) {
							echo '4th cell';
						}
					echo '</td>';
					$counter++;
				}
				echo '</tr>';
				if ($n > 3) 
				{
					$start_col = $column_fill[1];
					$curr_col = 3;
					$sequence = [$start_col, 5-$start_col, 1]; 
					for ($i = 1; $i < $n; $i++)
					{
						$curr_col=$sequence[$i>3?($i%3)-1:$i-1];
						echo '<tr style="height: 28px">';
						for ($j=$curr_col; $j<=$n; $j=$j+3)
						{
							echo '<td rowspan="'.($n - $i >= 3 ? 3: $n - $i).'">';
							if ($counter % 4 == 0) {
								echo '4th cell';
							}
							echo '</td>';
							$counter++;
						}
						echo '</tr>';
					}	
				}
			}
		?>
	</table>
	<script src="index4.js"></script>
</body>
</html>