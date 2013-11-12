<?php 

   include("include/config.php");

   $title="Min Me-sida om mig sj&auml;lv";

   $pageId = "me";

   // Define style thats specific for this page
   $pageStyle = '
   figure { 
   -webkit-border-radius: 10px;
   -moz-border-radius: 10px;
   border-radius: 10px;
   border-color:#5C0A0A;
   -moz-box-shadow: 10px 10px 5px #8A0F0F;
   -webkit-box-shadow: 10px 10px 5px #8A0F0F;
   box-shadow: 10px 10px 5px #8A0F0F;
   }';

   include("include/header.php"); 

?>

<h1>About</h1>
<p>Kristian "Bobby" Lundkvist. Exm&auml;sterist och ledamot i IT och Civ S&auml;ks linjef&ouml;rening Root. Pluggar tredje och sista &aring;ret p&aring; IT S&auml;k.</p>
<p>Utvecklar och driver tj&auml;nster i syftet att g&ouml;ra internet &auml;nnu mer decentraliserat &auml;n vad det redan &auml;r och g&ouml;ra det sv&aring;rare f&ouml;r myndigheter och f&ouml;retag att sp&aring;ra enskilda personer.</p>
<figure>
  <img src="img/me.png" alt="Profil Bild">
</figure>

<?php 

   include("include/byline.php");

   include("include/footer.php");
