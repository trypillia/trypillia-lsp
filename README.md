# trypillia-lsp

[![CI](https://github.com/trypillia/trypillia-lsp/actions/workflows/ci.yml/badge.svg)](https://github.com/trypillia/trypillia-lsp/actions/workflows/ci.yml)

Language Server Protocol implementation for the [Trypillia](https://github.com/trypillia/trypillia-language) programming language.

## Building

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

The binary will be at `build/trypillia-lsp`.

## Editor Setup

### VS Code

Install the [Trypillia extension](https://marketplace.visualstudio.com/items?itemName=trypillia.trypillia) from the marketplace.

### Neovim

```lua
vim.api.nvim_create_autocmd("FileType", {
  pattern = "try",
  callback = function()
    vim.lsp.start({
      name = "trypillia-lsp",
      cmd = { "trypillia-lsp" },
    })
  end,
})
```

## Contributing

Contributions are welcome and appreciated! Here's how you can contribute:

1. Fork the project
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

Please make sure to update tests as appropriate and adhere to the existing coding style.

## License

This project is licensed under the CSSM Unlimited License v2.0 (CSSM-ULv2). See the [LICENSE](LICENSE) file for details.
