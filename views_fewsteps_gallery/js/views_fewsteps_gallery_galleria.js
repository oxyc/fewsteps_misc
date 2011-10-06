
(function($) {
Drupal.behaviors.viewsFewstepsGalleryGalleria = {
  attach: function (context) {
    for (id in Drupal.settings.viewsFewstepsGalleryGalleria) {
      $('#' + id + ':not(.viewsFewstepsGalleryGalleria-processed)', context).addClass('viewsFewstepsGalleryGalleria-processed').each(function () {
        var settings = Drupal.settings.viewsFewstepsGalleryGalleria[$(this).attr('id')];

        settings = $.extend({
          height: 300,
          dataConfig: function(img) {
            return {
              description: $(img).next('figcaption').html()
            };
          },
        }, settings);
        // Fire up the Galleria.
        $(this).galleria(settings);
      });
    }
  }
}

})(jQuery);
