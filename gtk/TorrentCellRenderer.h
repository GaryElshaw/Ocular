// This file Copyright © 2007-2022 Mnemosyne LLC.
// It may be used under GPLv2 (SPDX: GPL-2.0), GPLv3 (SPDX: GPL-3.0),
// or any future license endorsed by Mnemosyne LLC.
// License text can be found in the licenses/ folder.

#pragma once

#include <memory>

#include <glibmm.h>
#include <gtkmm.h>

#include <libtransmission/tr-macros.h>

struct tr_torrent;

class TorrentCellRenderer : public Gtk::CellRenderer
{
public:
    TorrentCellRenderer();
    ~TorrentCellRenderer() override;

    TR_DISABLE_COPY_MOVE(TorrentCellRenderer)

    Glib::PropertyProxy<gpointer> property_torrent();
    Glib::PropertyProxy<double> property_piece_upload_speed();
    Glib::PropertyProxy<double> property_piece_download_speed();
    Glib::PropertyProxy<int> property_bar_height();
    Glib::PropertyProxy<bool> property_compact();

protected:
    void get_preferred_width_vfunc(Gtk::Widget& widget, int& minimum_width, int& natural_width) const override;
    void get_preferred_height_vfunc(Gtk::Widget& widget, int& minimum_height, int& natural_height) const override;
    void render_vfunc(
        Cairo::RefPtr<Cairo::Context> const& cr,
        Gtk::Widget& widget,
        Gdk::Rectangle const& background_area,
        Gdk::Rectangle const& cell_area,
        Gtk::CellRendererState flags) override;

private:
    class Impl;
    std::unique_ptr<Impl> const impl_;
};
