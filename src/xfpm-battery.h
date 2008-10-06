/* -*- Mode: C; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*-
 *
 * * Copyright (C) 2008 Ali <ali.slackware@gmail.com>
 *
 * Licensed under the GNU General Public License Version 2
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef __XFPM_BATTERY_H
#define __XFPM_BATTERY_H

#include <glib-object.h>

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "xfpm-enums.h"

G_BEGIN_DECLS

#define XFPM_TYPE_BATTERY    (xfpm_battery_get_type())
#define XFPM_BATTERY(o)      (G_TYPE_CHECK_INSTANCE_CAST(o,XFPM_TYPE_BATTERY,XfpmBattery))

typedef struct XfpmBatteryPrivate XfpmBatteryPrivate;

typedef struct
{
    GObject parent;
    XfpmBatteryPrivate *priv;
    
    gboolean ac_adapter_present;
    guint critical_level;
    XfpmCriticalAction critical_action;
    XfpmShowIcon show_tray;
    
    gboolean can_hibernate;
    gboolean can_suspend;
    gboolean show_sleep_errors;
    
#ifdef HAVE_LIBNOTIFY
    gboolean notify_enabled;
#endif        
    
} XfpmBattery;

typedef struct
{
    GObjectClass parent_class;
    
    /* signal */
    void  (*show_adapter_icon)    (XfpmBattery *batt,
                                   gboolean show);
                                   
} XfpmBatteryClass;

GType          xfpm_battery_get_type(void) G_GNUC_CONST;
XfpmBattery   *xfpm_battery_new     (void);
void           xfpm_battery_monitor (XfpmBattery *batt);

G_END_DECLS

#endif
