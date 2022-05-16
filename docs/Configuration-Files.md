## Locations

### macOS Defaults
<table>
<tr><th>What</th><th>Where</th></tr>
<tr><td>Per-torrent settings</td><td><tt>$HOME/Library/Application Support/Transmission</tt></td></tr>
<tr><td>Application settings</td><td><tt>$HOME/Library/Preferences/org.m0k.transmission.plist</tt></td></tr>
<tr><td>Default download folder</td><td><tt>$HOME/Downloads</tt></td></tr>
</table>

### Linux / GTK Defaults
<table>
<tr><th>What</th><th>Where</th></tr>
<tr><td>GTK+/Qt client settings</td><td><tt>$HOME/.config/transmission</tt></td></tr>
<tr><td>Daemon settings</td><td><tt>$HOME/.config/transmission-daemon</tt></td></tr>
<tr><td>CLI settings</td><td><tt>$HOME/.config/transmission-cli</tt></td></tr>
<tr><td>Default download folder</td><td><tt>$HOME/Downloads</tt></td></tr>
</table>

Some Linux distributions' start script for transmission-daemon use different location. This varies by distribution, but two paths sometimes used are `/var/lib/transmission-daemon` and `/var/run/transmission`.

If you want to swap between the two applications, all you have to do is pass in a different config directory with the -g command-line option. For example, to have the daemon pick up where the GTK+ client left off, run `transmission-daemon -g ~/.config/transmission`.

### Windows Defaults
<table>
<tr><th>What</th><th>Where</th></tr>
<tr><td>Qt client settings</td><td><tt>%LOCALAPPDATA%/transmission</tt></td></tr>
<tr><td>Daemon settings</td><td><tt>%LOCALAPPDATA%/transmission-daemon</tt></td></tr>
<tr><td>Default download folder</td><td><tt>%LOCALAPPDATA%/Downloads</tt></td></tr>
</table>

`%LOCALAPPDATA%` will resolve to `C:\Users[username]\AppData\Local` under a user context, and `C:\Windows\ServiceProfiles\LocalService\AppData\Local` under a service context.

### Overriding the Defaults

The per-user configuration folder's location can be overridden by setting `TRANSMISSION_HOME` and/or other [environment variables](Environment-Variables.md).

## Files
The configuration folder typically has the following files:

### settings.json
This is a JSON-encoded file that holds all the client's settings and preferences. It's currently only used by the daemon, GTK+ and CLI clients. JSON was chosen because it's mostly human-readable and -writable, but also allows data hierarchies to be stored. See the [Editing Configuration Files](Editing-Configuration-Files.md) page on how to modify them.

### stats.json
This is a JSON-encoded file that holds session statistics such as running upload and download byte counts.

### torrents/
This subfolder holds the .torrent files that have been added to Transmission. The files in this folder are named with a combination of the torrent's name (to make it human-readable) and a portion of the torrent's SHA1 hash (to avoid filename collisions from similarly-named torrents).

### resume/
This subfolder holds .resume files that hold information about a particular torrent, such as which parts have been downloaded, the folder the downloaded data was stored in, and so on. These follow an identical naming scheme to the files in the torrents subfolder.

### blocklists/
This subfolder holds Bluetack-formatted blocklists. Files ending in ".bin" are generated by Transmission as it parses a Bluetack file and stores it into a binary format for faster lookups. On startup, Transmission will try to parse any non-".bin" file and generate a new blocklist from it, so you can have multiple blocklists just by copying new Bluetack files into this location. See [Blocklists](./Blocklists.md) for more information.

## Legacy Versions of Transmission
Older, [pre-XDG](http://standards.freedesktop.org/basedir-spec/basedir-spec-latest.html) [versions](http://trac.transmissionbt.com/ticket/684) of transmission-GTK and transmission-daemon stored their settings in `$HOME/.transmission`. Newer releases try to automatically migrate these files to `$HOME/.config/transmission/`.