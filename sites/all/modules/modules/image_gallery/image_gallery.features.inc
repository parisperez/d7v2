<?php
/**
 * @file
 * image_gallery.features.inc
 */

/**
 * Implements hook_views_api().
 */
function image_gallery_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function image_gallery_image_default_styles() {
  $styles = array();

  // Exported image style: gallery_thumbnail.
  $styles['gallery_thumbnail'] = array(
    'name' => 'gallery_thumbnail',
    'label' => 'gallery_thumbnail',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function image_gallery_node_info() {
  $items = array(
    'my_gallery_image' => array(
      'name' => t('My Gallery Image'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('My Gallery Image Title'),
      'help' => '',
    ),
  );
  return $items;
}
