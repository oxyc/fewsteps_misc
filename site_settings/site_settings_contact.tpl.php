<?php
/**
 * $vcard['']
 */
?>
<div class="vcard">
  <a class="fn url <?php print $fn['org'] ? $fn['org'] : ''; ?>" href="<?php print $url; ?>"><?php print $fn['fn']; ?></a>
<?php if($adr['street-address'] || $adr['locality'] || $adr['postal-code'] || $adr['country-name']): ?>
  <div class="adr">
  <?php if($adr['street-address']): ?>
    <div class="street-address"><?php print $adr['street-address']; ?></div>
  <?php endif; ?>
  <?php if($adr['postal-code']): ?>
    <span class="postal-code"><?php print $adr['postal-code']; ?></span>
  <?php endif; ?>
  <?php if($adr['locality']): ?>
    <span class="locality"><?php print $adr['locality']; ?></span>
  <?php endif; ?>
  <?php if($adr['country-name']): ?>
    <div class="country-name"><?php print $adr['country-name']; ?></div>
  <?php endif; ?>
  </div>
<?php endif; ?>
<?php if($tel): ?>
  <div class="tel"><?php print $tel; ?></div>
<?php endif; ?>
<?php if($email): ?>
  <div class="email"><?php print $email; ?><div>
<?php endif;?>
</div>
