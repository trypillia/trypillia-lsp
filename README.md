# trypillia-lsp

[![CI](https://github.com/trypillia/trypillia-lsp/actions/workflows/ci.yml/badge.svg)](https://github.com/trypillia/trypillia-lsp/actions/workflows/ci.yml)

Language Server Protocol implementation for the [Trypillia](https://github.com/trypillia/trypillia-language) programming language. Provides IDE features like autocompletion, hover info, diagnostics, and semantic highlighting for any LSP-compatible editor.

## Building

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

The binary will be at `build/trypillia-lsp`.

## Scripts

### Sorting `native_docs.json`

The `resources/native_docs.json` file should be kept sorted by key for consistent diffs. Use the sort script to reorder entries:

```bash
python3 scripts/sort_native_docs.py
```

This reads `resources/native_docs.json`, sorts all entries alphabetically by key, and writes the result back in-place. A custom path can be supplied:

```bash
python3 scripts/sort_native_docs.py /path/to/native_docs.json
```

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
