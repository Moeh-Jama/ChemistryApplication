<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>
	<?php
		/*$arry;
		$i=0;
		$myfile =fopen("elements.txt", "r") or die("Unable to open file!");
		echo "ppp<br>";
		while(fgetc($myfile)!="\n")
		{
			$arry[$i] = fgetc($myfile);
			$i++;
		}
		echo "FUll";
		echo $arry;
		echo fgetc($myfile);
		echo "<br>ppp";
		fclose($myfile); */
		


		$handle = @fopen("elements.txt", "r");
		if ($handle) {
		    while (($buffer = fgets($handle, 50)) !== false) {
		        echo $buffer;
		        echo "<br>";
		    }
		    if (!feof($handle)) {
		        echo "Error: unexpected fgets() fail\n";
		    }
		    fclose($handle);
		}
		/*echo"<br><br><br><br><p>ENDING</p>";
		$filecontents = file_get_contents('elements.txt');
		echo "Here<br>";
		echo $filecontents;
		echo"DoneHEre<br>";
		$words = preg_split('/[\s]+/', $filecontents, -1, PREG_SPLIT_NO_EMPTY);

		print_r($words);
		echo "<br><p>DONE</p><br>"
 }
 fclose($fp);*/
	?>
</body>
</html>