<html>
<head>
<link href="//maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css" rel="stylesheet">
<script src="//ajax.googleapis.com/ajax/libs/jquery/1.11.0/jquery.js"></script>
<script>
$('#introtext', window.parent.document).hide();
</script>
</head>
<body onload="window.parent.parent.scrollTo(0,0)">
Oops, your card was declined.  Please click your browser back button, review the information and resubmit.<br/><br/>
<?php
 echo rawurldecode($_GET['on']);
?>
</body>
</html>
