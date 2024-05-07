# get-kernel-sources
Get the Kernel sources for actuated to build with kmod or DKMS etc

Usage:

```yaml
- uses: self-actuated/get-kernel-sources@master
```

The version will be determined via `uname -r`, i.e. `5.10.201`.

In this instance, the sources would be be downloaded to `/usr/src/linux-headers-5.10.201` with a `source` and `build` folder being generated.

You can then proceed with a DKMS or kmod build of whatever you require such as eBPF, Wireguard, or ZFS.

## Caching the sources

Caching with [actions/cache](https://github.com/actions/cache) is likely to improve the speed of getting the Kernel sources, rather than fetching them directly from git.

The following workflow factors in the OS, CPU archiecture and Kernel version into the cache key:

```yaml
    steps:
      - name: Reset permissions of /usr/src for runner
        run: |
          sudo chown -R runner:docker /usr/src
      - name: Set TARGET_ARCH
        run: |
          echo "TARGET_ARCH=$(uname -m)" >> $GITHUB_ENV
      - name: Set KERNEL_VERSION
        run: |
          echo "KERNEL_VERSION=$(uname -r)" >> $GITHUB_ENV
      - name: Cache Kernel sources
        id: cache-kernel-sources
        uses: actions/cache@v4
        with:
          path: |
            /usr/src/linux
          key: ${{ runner.os }}-${{ env.TARGET_ARCH }}-${{env.KERNEL_VERSION}}

      - if: ${{ steps.cache-kernel-sources.outputs.cache-hit != 'true' }}
        uses: self-actuated/get-kernel-sources@master
```

For example:

```bash
Cache Size: ~434 MB (454865493 B)
Cache saved successfully
Cache saved with key: Linux-aarch64-6.1.90
```
