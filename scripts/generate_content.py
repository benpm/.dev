#!/usr/bin/env python3
"""
Script to generate Zola content from the execution logs.
This script reads the source code and output from each example
and generates markdown files for Zola to process.
"""

import os
import re
import sys
from pathlib import Path

# Language configurations
LANGUAGES = [
    {"id": "c", "title": "C", "emoji": "🔧", "lang": "c", "source_ext": "c"},
    {"id": "cpp", "title": "C++", "emoji": "⚙️", "lang": "cpp", "source_ext": "cpp"},
    {"id": "javascript", "title": "JavaScript", "emoji": "🟨", "lang": "javascript", "source_ext": "js"},
    {"id": "python", "title": "Python", "emoji": "🐍", "lang": "python", "source_ext": "py"},
    {"id": "rust", "title": "Rust", "emoji": "🦀", "lang": "rust", "source_ext": "rs"},
    {"id": "nim", "title": "Nim", "emoji": "👑", "lang": "nim", "source_ext": "nim"},
]

# ANSI escape code pattern
ANSI_ESCAPE = re.compile(r'\x1B(?:[@-Z\\-_]|\[[0-?]*[ -/]*[@-~])')


def strip_ansi_codes(s: str) -> str:
    """Remove ANSI escape codes from a string."""
    return ANSI_ESCAPE.sub('', s)


def escape_toml_string(s: str) -> str:
    """Escape a string for use in TOML triple-quoted basic strings.
    
    Uses multi-line basic strings (triple double quotes) with proper escaping.
    """
    # Strip ANSI escape codes first
    s = strip_ansi_codes(s)
    # Escape backslashes first, then double quotes
    s = s.replace("\\", "\\\\")
    s = s.replace('"', '\\"')
    return s


def create_section_index(content_dir: Path, lang_config: dict) -> None:
    """Create the _index.md file for a language section."""
    section_dir = content_dir / lang_config["id"]
    section_dir.mkdir(parents=True, exist_ok=True)
    
    index_content = f"""+++
title = "{lang_config['title']}"
sort_by = "title"
template = "section.html"

[extra]
emoji = "{lang_config['emoji']}"
id = "{lang_config['id']}"
lang = "{lang_config['lang']}"
+++
"""
    
    (section_dir / "_index.md").write_text(index_content)


def process_language(logs_dir: Path, content_dir: Path, lang_config: dict) -> None:
    """Process all examples for a given language."""
    lang_id = lang_config["id"]
    source_ext = lang_config["source_ext"]
    
    examples_dir = logs_dir / f"{lang_id}-logs" / "examples"
    output_dir = content_dir / lang_id
    
    if not examples_dir.exists():
        print(f"No examples found for {lang_id} at {examples_dir}")
        return
    
    for example_dir in examples_dir.iterdir():
        if not example_dir.is_dir():
            continue
        
        example_name = example_dir.name
        source_file = example_dir / f"source.{source_ext}"
        output_file = example_dir / "output.txt"
        
        source_code = ""
        output = ""
        
        if source_file.exists():
            source_code = source_file.read_text()
        
        if output_file.exists():
            output = output_file.read_text()
        
        # Escape the content for TOML
        source_code_escaped = escape_toml_string(source_code)
        output_escaped = escape_toml_string(output)
        
        # Create the markdown file using triple double quotes for multi-line basic strings
        md_content = f'''+++
title = "{example_name}"

[extra]
source_code = """
{source_code_escaped}
"""
output = """
{output_escaped}
"""
+++
'''
        
        md_file = output_dir / f"{example_name}.md"
        md_file.write_text(md_content)
        print(f"Created {md_file}")


def main():
    # Get the project root (assuming script is in scripts/)
    script_dir = Path(__file__).parent
    project_root = script_dir.parent
    
    logs_dir = project_root / "logs"
    content_dir = project_root / "site" / "content"
    
    # Check if logs directory exists
    if not logs_dir.exists():
        print(f"Error: Logs directory not found at {logs_dir}")
        sys.exit(1)
    
    # Create content directories and section indexes
    for lang_config in LANGUAGES:
        create_section_index(content_dir, lang_config)
        process_language(logs_dir, content_dir, lang_config)
    
    print("Content generation complete!")


if __name__ == "__main__":
    main()
