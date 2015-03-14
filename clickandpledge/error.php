<?php
require_once('inc/config.inc');

$msg = "The following error occured:\n\n";
$msg .= rawurldecode($_GET['err']) . "\n";
$msg .= rawurldecode($_GET['on']);

mail(ERROR_EMAIL_TO,ERROR_EMAIL_SUBJECT,$msg);
?>
<html>
<head>
<link href="//maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css" rel="stylesheet">
<script src="//ajax.googleapis.com/ajax/libs/jquery/1.11.0/jquery.js"></script>
<script>
$('#introtext', window.parent.document).hide();
</script>

</head>
<body onload="window.parent.parent.scrollTo(0,0)">
Error<br/><br/>
<?php
 echo rawurldecode($_GET['err']);
 echo rawurldecode($_GET['on']);
?>
</body>
</html>
