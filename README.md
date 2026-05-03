# librazermacos

### Important Note
This is not the original repo the original repo is from [1kc/librazermacos](https://github.com/1kc/librazermacos) I forked this repo to maintain it as the original seems to be abandoned.

C library of openrazer drivers ported to macOS.

Exposed as a shared/dynamic library - `librazermacos.so` to provider interoperability with various frontends.

Includes a sample CLI implementation in C to demonstrate driver function calls.

To build the shared library and sample cli
```bash
make
```
Running the CLI
```bash
./sample_cli
```

To build the shared library only.
```bash
make librazermacos.so
```

## razer-macos frontend
[razer-macos](https://github.com/stickoking/librazermacos) does not actually build `librazermacos.so`, instead the drivers are built by [binding.gyp](https://github.com/1kc/razer-macos/blob/master/binding.gyp).
