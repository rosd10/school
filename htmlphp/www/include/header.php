<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title><?php echo $title; ?></title>
    <link rel="shortcut icon" href="img/favicon.ico">
    <link rel="stylesheet" href="style/stylesheet.css" title="General Stylesheet">
    <link rel="alternate stylesheet" href="style/debug.css" title="Debug Stylesheet">
  </head>

  <body <?php if(isset($pageId)) echo " id='$pageId' "; ?>>
    <header>
      <a href="me.php"><img src="img/logo.png" alt="htmlphp logo" width=200 height=200></a>
    </header>
    <header>
      <!-- Navigeringsmeny -->
      <nav class="navmenu">
	<a id="me-" href="me.php">Me</a>
	<a id="report-" href="report.php">Redovisning</a>
	<a id="source-" href="viewsource.php">K&auml;llkod</a>
      </nav>
    </header>
    <! Each page can set $pageStyle to create additional style >
    <?php if(isset($pageStyle)) : ?>
    <style type="text/css">
      <?php echo $pageStyle; ?>
      </style>
    <?php endif; ?>
    
    <div id="content" class="round-corners" >
