
<?php 
   $title="Mina redovisningar av kursmomenten";
   $pageId="report";
   include("include/header.php");
?>

<h1>Redovisning</h1>
<p>Momentet var i sig r&auml;tt l&auml;tt, testade allt mot min egna server. Anv&auml;nder Windows 7 alternativt BackTrack5 som operativsystem vilket gav lite strul d&aring; Windows 7 inte har uppt&auml;ckt UTF-8 &auml;n. Sitter p&aring; Firefox med ett g&auml;ng extentions som NoScript och liknande. Utvecklingsmilj&ouml;n p&aring; Windows best&aring;r av Git for Windows, Emacs, WinSCP och Putty. P&aring; Linux &auml;r det openssh, sftp, git och Emacs.</p>
<p>Problemen jag st&ouml;tt p&aring; &auml;r f&ouml;r det mesta relaterade till r&auml;ttigheter, gl&ouml;mde st&auml;lla in r&auml;tt umask och liknande. Har &auml;ven haft strul med git p&aring; skolans milj&ouml;, den f&aring;r connection timed out n&auml;r den ska ansluta till min server via ssh. Skulle ha fels&ouml;kt lite mer om de inte begr&auml;nsat s&aring; att man inte f&aring;r anv&auml;nda ping. Unicorn f&aring;r ocks&aring; spel p&aring; min sida n&auml;r jag delat upp den i header och footer, vet inte om det &auml;r k&auml;nt problem d&aring; koden ser r&auml;tt ut (det vill s&auml;ga som referens koden).</p>

<?php
include("include/byline.php");
include("include/footer.php");
