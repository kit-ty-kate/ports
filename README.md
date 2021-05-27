## decke@ FreeBSD Portstree
This is my custom FreeBSD ports overlay that I use for testing and development.

**Do not use this portstree yourself unless you really know what you are doing.**

## How to use this repository as an overlay with poudriere

1. Install poudriere-devel package:

```
pkg install poudriere-devel
```

**Note:** `poudriere` package doesn't include required overlays fixes.

For information about configuring `poudriere` please refer to wiki: https://github.com/freebsd/poudriere/wiki

2. Configure ports trees

If you already have main ports directory you can re-use it with poudriere:

```
poudriere ports -c -p default -m null -M /usr/ports
```

If you don't ports yet, you can ask poudriere to add it for you:

```
poudriere ports -c -p default -m git+ssh -M /usr/ports
```

Next, add ports from this repository:

```
poudriere ports -c -U https://github.com/decke/ports.git -p decke-ports -m git -B master
```

3. Prepare jail for builds:

```
poudriere jail -c -j 13-0-adm64 -v stable/13 -a amd64 -m git
```

4. Build package using this repository as overlay

```
poudriere bulk  -j 13-0-adm64 -O decke-ports sysutils/docker-engine
```

Ready to use packages should exist in `/poudriere/data/packages/13-0-adm64-default/All` directory.
