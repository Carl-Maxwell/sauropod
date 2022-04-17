These are some general style guidelines for this project.

# General
- These style guidelines are intended to be inline with the Hazel project
- Public stuff is declared first, private stuff declared afterwards
- Scope Braces:
	- One line methods can be on the same line, but
	- Scope braces are usually put on the next line, like:

```c++
void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			HZ_TRACE(e);
		}
	}
```

# Identifiers
- Class identifiers are capitalized CamelCase (like VertexBuffer)
- Methods & functions are capitalized camelCase (like IsInCategory)
- Variables are uncapitalized camelCase (like index_buffer_obj)
- Member variables are prefixed with "m_" (like m_KeyCode)
- Member variables of static classes are prefixed with "s_" (like s_EngineLogger)
- namespaces are Capitalized (like Sauropod::)
- acronyms:
	- Acronyms in class names should be ... tbd
	- Acronyms elsewhere should be ...tbd


# Other
- filenames are capitalized CamelCase
- four space tabs-as-tabs

# Comments


