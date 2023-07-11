
# libtorrent

A modern wrapper around [arvidn/libtorrent](https://github.com/arvidn/libtorrent) for use in NodeJS with Typescript support


## Installation

The C++ project builds a NodeJS addon that is dynamically loaded. It depends on the following libraries - 

- Boost
- OpenSSL
> If you get a compilation error that includes the text: <br/> `openssl_api_compat expresses an impossible api compatibility level` <br /> It means that you need a newer/different version of OpenSSL as the one installed on your system can't be used. Be careful when updating it as you may break Linux

We also need the following - 
- A recent version of [Node.js](https://nodejs.org/en) (>= 14.0.0)
- A recent version of [npm](https://www.npmjs.com/)
- A recent version of [Cmake](https://cmake.org/)
- A compatible C++ compiler (g++ or clang)

> Note: MACOS builds will fail with clang++. See [this](https://github.com/arvidn/libtorrent/issues/7455) issue

> Windows Visual Studio and ARM will be supported soon
## Documentation

- Check out the wiki pages for this repo


## Run Locally

Clone the project

```bash
  git clone git@github.com:P2PFlix/libtorrent.git
```

Go to the project directory

```bash
  cd libtorrent
```

Install dependencies

```bash
  npm install
```

Build the addon

```bash
  npm run build
```


## Contributing

Contributions are always welcome!

See `contributing.md` for ways to get started.

Please adhere to this project's `code of conduct`.


## License

[MIT](https://choosealicense.com/licenses/mit/)


## Roadmap

- Additional browser support

- Windows build support


