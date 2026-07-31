# trypillia-lsp

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

## License

This project is licensed under the CSSM Unlimited License v2.0 (CSSM-ULv2). See the [LICENSE](LICENSE) file for details.
