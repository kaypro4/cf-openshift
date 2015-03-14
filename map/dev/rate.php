<?php
error_reporting(E_ALL);
ini_set('display_errors', '1');
session_start(); 
include '/var/chroot/home/content/22/10639522/html/map/thumbsup/init.php';
if (isset($_GET["ID"])) {
  $_SESSION['ID']=$_GET["ID"];
}
?>
<!DOCTYPE html>
<head>
<?php echo ThumbsUp::css() ?>
<script src="http://code.jquery.com/jquery-1.8.2.min.js"></script>
<?php echo ThumbsUp::javascript() ?>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>Rate</title>
</head>
<body>
<div style="font-family: sans-serif; font-size:75%; width:200px;">
<table cellpadding="2" width="200px">
	<tr>
	<td width="50%" align="center">Taste good?<?php echo ThumbsUp::item($_SESSION['ID'].'-flavor')->template('up_down') ?></td>
	<td width="50%" align="center">Pest free?<?php echo ThumbsUp::item($_SESSION['ID'].'-pests')->template('up_down') ?></td>
	</tr>
</table>

</div>
</body>
</html>