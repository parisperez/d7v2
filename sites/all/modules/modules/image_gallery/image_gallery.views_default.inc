<?php
/**
 * @file
 * image_gallery.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function image_gallery_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'photo_gallery';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Photo Gallery';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Photo Gallery';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['style_options']['fill_single_line'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Relationship: Content: Tags (field_animal_tags) */
  $handler->display->display_options['relationships']['field_animal_tags_tid']['id'] = 'field_animal_tags_tid';
  $handler->display->display_options['relationships']['field_animal_tags_tid']['table'] = 'field_data_field_animal_tags';
  $handler->display->display_options['relationships']['field_animal_tags_tid']['field'] = 'field_animal_tags_tid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: my gallery image */
  $handler->display->display_options['fields']['field_mygalleryimagefield_1']['id'] = 'field_mygalleryimagefield_1';
  $handler->display->display_options['fields']['field_mygalleryimagefield_1']['table'] = 'field_data_field_mygalleryimagefield';
  $handler->display->display_options['fields']['field_mygalleryimagefield_1']['field'] = 'field_mygalleryimagefield';
  $handler->display->display_options['fields']['field_mygalleryimagefield_1']['label'] = '';
  $handler->display->display_options['fields']['field_mygalleryimagefield_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mygalleryimagefield_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_mygalleryimagefield_1']['settings'] = array(
    'image_style' => 'gallery_thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_animal_tags']['id'] = 'field_animal_tags';
  $handler->display->display_options['fields']['field_animal_tags']['table'] = 'field_data_field_animal_tags';
  $handler->display->display_options['fields']['field_animal_tags']['field'] = 'field_animal_tags';
  $handler->display->display_options['fields']['field_animal_tags']['label'] = '';
  $handler->display->display_options['fields']['field_animal_tags']['element_label_colon'] = FALSE;
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'field_animal_tags_tid';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'my_gallery_image' => 'my_gallery_image',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');

  /* Display: Photo Gallery */
  $handler = $view->new_display('page', 'Photo Gallery', 'page');
  $handler->display->display_options['path'] = 'photo-gallery/%';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['photo_gallery'] = $view;

  return $export;
}
