/* clutter-text-buffer.h
 * Copyright (C) 2011 Collabora Ltd.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * Author: Stef Walter <stefw@collabora.co.uk>
 */

#if !defined(__CLUTTER_H_INSIDE__) && !defined(CLUTTER_COMPILATION)
#error "Only <clutter/clutter.h> can be included directly."
#endif

#ifndef __CLUTTER_TEXT_BUFFER_H__
#define __CLUTTER_TEXT_BUFFER_H__

#include <glib-object.h>

G_BEGIN_DECLS

/* Maximum size of text buffer, in bytes */
#define CLUTTER_TEXT_BUFFER_MAX_SIZE        G_MAXUSHORT

#define CLUTTER_TYPE_TEXT_BUFFER            (clutter_text_buffer_get_type ())
#define CLUTTER_TEXT_BUFFER(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), CLUTTER_TYPE_TEXT_BUFFER, ClutterTextBuffer))
#define CLUTTER_TEXT_BUFFER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), CLUTTER_TYPE_TEXT_BUFFER, ClutterTextBufferClass))
#define CLUTTER_IS_TEXT_BUFFER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CLUTTER_TYPE_TEXT_BUFFER))
#define CLUTTER_IS_TEXT_BUFFER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CLUTTER_TYPE_TEXT_BUFFER))
#define CLUTTER_TEXT_BUFFER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), CLUTTER_TYPE_TEXT_BUFFER, ClutterTextBufferClass))

typedef struct _ClutterTextBuffer            ClutterTextBuffer;
typedef struct _ClutterTextBufferClass       ClutterTextBufferClass;
typedef struct _ClutterTextBufferPrivate     ClutterTextBufferPrivate;

struct _ClutterTextBuffer
{
  GObject parent_instance;

  /*< private >*/
  ClutterTextBufferPrivate *priv;
};

struct _ClutterTextBufferClass
{
  GObjectClass parent_class;

  /* Signals */

  void         (*inserted_text)          (ClutterTextBuffer *buffer,
                                          guint              position,
                                          const gchar       *chars,
                                          guint              n_chars);

  void         (*deleted_text)           (ClutterTextBuffer *buffer,
                                          guint              position,
                                          guint              n_chars);

  /* Virtual Methods */

  const gchar* (*get_text)               (ClutterTextBuffer *buffer,
                                          gsize             *n_bytes);

  guint        (*get_length)             (ClutterTextBuffer *buffer);

  guint        (*insert_text)            (ClutterTextBuffer *buffer,
                                          guint              position,
                                          const gchar       *chars,
                                          guint              n_chars);

  guint        (*delete_text)            (ClutterTextBuffer *buffer,
                                          guint              position,
                                          guint              n_chars);

  /* Padding for future expansion */
  void (*_clutter_reserved1) (void);
  void (*_clutter_reserved2) (void);
  void (*_clutter_reserved3) (void);
  void (*_clutter_reserved4) (void);
  void (*_clutter_reserved5) (void);
  void (*_clutter_reserved6) (void);
  void (*_clutter_reserved7) (void);
  void (*_clutter_reserved8) (void);
};

GType               clutter_text_buffer_get_type            (void) G_GNUC_CONST;

ClutterTextBuffer*  clutter_text_buffer_new                 (void);

ClutterTextBuffer*  clutter_text_buffer_new_with_text       (const gchar       *text,
                                                             gssize             text_len);

gsize               clutter_text_buffer_get_bytes           (ClutterTextBuffer *buffer);

guint               clutter_text_buffer_get_length          (ClutterTextBuffer *buffer);

const gchar*        clutter_text_buffer_get_text            (ClutterTextBuffer *buffer);

void                clutter_text_buffer_set_text            (ClutterTextBuffer *buffer,
                                                             const gchar       *chars,
                                                             gint               n_chars);

void                clutter_text_buffer_set_max_length      (ClutterTextBuffer *buffer,
                                                             gint               max_length);

gint                clutter_text_buffer_get_max_length      (ClutterTextBuffer  *buffer);

guint               clutter_text_buffer_insert_text         (ClutterTextBuffer *buffer,
                                                             guint              position,
                                                             const gchar       *chars,
                                                             gint               n_chars);

guint               clutter_text_buffer_delete_text         (ClutterTextBuffer *buffer,
                                                             guint              position,
                                                             gint               n_chars);

void                clutter_text_buffer_emit_inserted_text  (ClutterTextBuffer *buffer,
                                                             guint              position,
                                                             const gchar       *chars,
                                                             guint              n_chars);

void                clutter_text_buffer_emit_deleted_text   (ClutterTextBuffer *buffer,
                                                             guint              position,
                                                             guint              n_chars);

G_END_DECLS

#endif /* __CLUTTER_TEXT_BUFFER_H__ */