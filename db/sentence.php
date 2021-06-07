<?
function pushData(){
	$datafile = "./sentence.dat";
	if(file_exists($datafile)){
		$file_size = filesize($datafile)+1;
		$fp = fopen($datafile,"r");
		$data = fgets($fp, $file_size);
		fclose($fp);
		$data++;
		$data_len = strlen("$data");
		$fp=fopen($datafile,"w");
		fputs($fp, $data, $data_len);
		fclose();
		for($i=0; $i<$data_len; $i++) {
			$numstr=substr($data, $i, 1);
			print "<img src=/num_imgs/$numstr.jpg>"; 
		}
		return 1;
	}
	else{
		print "sentence.dat 파일이 존재하지 않습니다. <br>\n";
		return 0;
	}
}
?>