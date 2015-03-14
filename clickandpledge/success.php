<html>
<head>
<title>Success</title>
<link href="//maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css" rel="stylesheet">
<script src="//ajax.googleapis.com/ajax/libs/jquery/1.11.0/jquery.js"></script>
<script>
$('#introtext', window.parent.document).hide();
</script>
</head>
<body onload="window.parent.parent.scrollTo(0,0)">
Thank you for your donation.  You will recieve a receipt to the e-mail that you provided.
<br/><br/>
If you need to reference this transaction, please use tracking code #
<?php
echo rawurldecode($_GET['on']);
?>
</body>
</html>
