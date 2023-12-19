# get-kernel-sources
Get the Kernel sources for actuated to build with kmod or DKMS etc

Usage:

```yaml
- uses: self-actuated/get-kernel-sources@master
```

The version will be determined via `uname -r`, i.e. `5.10.201`.

In this instance, the sources would be be downloaded to `/usr/src/linux-headers-5.10.201` with a `source` and `build` folder being generated.

You can then proceed with a DKMS or kmod build of whatever you require such as eBPF, Wireguard, or ZFS.
