<?php 
   include("include/config.php");

   $pageTitle = "Visa k�llkod";
   $pageId = "source";

   // Include code from source.php to display sourcecode-viewer
   $sourceBasedir=dirname(__FILE__);
   $sourceNoEcho=true;
   include("source.php");
   $pageStyle=$sourceStyle;
?>


<?php include("include/header.php"); ?>

<!-- Sidans/Dokumentets huvudsakliga inneh�ll -->
<div id="content">
<?php echo "$sourceBody"; ?>
<hr>
</div>

<?php include("include/footer.php"); ?>
