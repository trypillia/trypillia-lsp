#!/usr/bin/env python3
"""Sort native_docs.json by key in alphabetical order.

Usage:
    python3 sort_native_docs.py
    python3 sort_native_docs.py /path/to/native_docs.json
"""

import json
import sys
from pathlib import Path

DEFAULT_PATH = Path(__file__).resolve().parent.parent / "resources" / "native_docs.json"


def sort_native_docs(path: Path) -> None:
    with path.open("r", encoding="utf-8") as f:
        data = json.load(f)

    sorted_data = dict(sorted(data.items()))

    with path.open("w", encoding="utf-8") as f:
        json.dump(sorted_data, f, ensure_ascii=False, indent=2)
        f.write("\n")

    print(f"Sorted {len(sorted_data)} entries in {path}")


if __name__ == "__main__":
    target = Path(sys.argv[1]) if len(sys.argv) > 1 else DEFAULT_PATH
    sort_native_docs(target)
