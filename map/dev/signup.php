<?php
error_reporting(E_ALL);
ini_set('display_errors', '1');
?>
<!DOCTYPE html>
<head>
<link rel="stylesheet" href="http://code.jquery.com/mobile/1.3.0/jquery.mobile-1.3.0.min.css" />
<link rel="stylesheet" href="cityfruit.min.css" />
<script src="http://code.jquery.com/jquery-1.8.2.min.js"></script>
<script src="http://code.jquery.com/mobile/1.3.0/jquery.mobile-1.3.0.min.js"></script>

<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />

<title>City Fruit Steward sign up</title>
<script type="text/javascript">
function getQuerystring(key, default_)
{
  if (default_==null) default_=""; 
  key = key.replace(/[\[]/,"\\\[").replace(/[\]]/,"\\\]");
  var regex = new RegExp("[\\?&]"+key+"=([^&#]*)");
  var qs = regex.exec(window.location.href);
  if(qs == null)
    return default_;
  else
    return qs[1];
}
$(document).ready(function() {
  $("form").submit(function() {
    var $form = $(this);
    // submit form
    $.post($form.attr('action'), $form.serializeArray());
    // alert
    alert("The request has been submitted.");
    // close window
    window.close();
    // return
    return false;
  });
});

</script>

</head>
<body>

<div data-role="dialog">
	
		<div data-role="header" data-theme="d">
			<h1>Sign up to volunteer</h1>
		</div>
		
		<div data-role="content">
		<?php
		if(isset($_GET['sitename'])) {
			$sitename = $_GET['sitename'];
		}elseif(isset($_POST['sitename'])) {
			$sitename = $_POST['sitename'];
		}else{
			$sitename = "Not provided";
		}
	
		if(isset($_POST['text-email'])) {
			 
			// EDIT THE 2 LINES BELOW AS REQUIRED
			$email_to = "i8flan@gmail.com";
			$email_subject = "Orchard steward volunteer signup";
			 
			 
			function died($error) {
				// your error code can go here
				echo "We are very sorry, but there were error(s) found with the form you submitted. ";
				echo "These errors appear below.<br /><br />";
				echo $error."<br /><br />";
				echo "Please go back and fix these errors.<br /><br />";
				die();
			}
			 
			// validation expected data exists
			if(!isset($_POST['text-name']) ||
				!isset($_POST['text-email']) ||
				!isset($_POST['comments'])) {
				died('We are sorry, but there appears to be a problem with the form you submitted.');       
			}
			 
			$first_name = $_POST['text-name']; // required
			$email_from = $_POST['text-email']; // required
			$site_name = $_POST['sitename']; // required
			$comments = $_POST['comments']; 
			 
			$error_message = "";
			$email_exp = '/^[A-Za-z0-9._%-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}$/';
		  if(!preg_match($email_exp,$email_from)) {
			$error_message .= 'The Email Address you entered does not appear to be valid.<br />';
		  }
			$string_exp = "/^[A-Za-z .'-]+$/";
		  if(!preg_match($string_exp,$first_name)) {
			$error_message .= 'The Name you entered does not appear to be valid.<br />';
		  }
		  if(strlen($error_message) > 0) {
			died($error_message);
		  }
			$email_message = "Form details below.\n\n";
			 
			function clean_string($string) {
			  $bad = array("content-type","bcc:","to:","cc:","href");
			  return str_replace($bad,"",$string);
			}
			 
			$email_message .= "First Name: ".clean_string($first_name)."\n";
			$email_message .= "Email: ".clean_string($email_from)."\n";
			$email_message .= "Site: ".clean_string($site_name)."\n";
			$email_message .= "Comments: ".clean_string($comments)."\n";
			 
			 
		// create email headers
		$headers = 'From: '.$email_from."\r\n".
		'Reply-To: '.$email_from."\r\n" .
		'X-Mailer: PHP/' . phpversion();
		@mail($email_to, $email_subject, $email_message, $headers);  
		?>
		 
		<!-- include your own success html here -->
		 
		<b>Thank you for signing up!</b><br>
		 
		<?php
		}
		?>
		
		<form action="signup.php" method="post" id="myform">
			<label for="text-name">Your name:</label>
			<input type="text" name="text-name" id="text-name" value="">
			<label for="text-email">Your e-mail:</label>
			<input type="text" name="text-email" id="text-email" value="">
			<label for="comments">Comments:</label>
			<textarea cols="40" rows="8" name="comments" id="comments"></textarea>
			<input type="submit" value="Submit" data-iconpos="right" data-mini="true" data-theme="e">
			<!--<a href="#" data-role="button" data-rel="back">Submit</a>-->
			<input type="hidden" name="sitename" value="<?=$sitename?>">
		</form>
		</div>
	</div>


</body>
</html>