uintptr_t label, skin;
bool inited; uintptr_t draw_shader;

uintptr_t linetexture = 0;
int linetextureID = 0;

static float pulsation(float minVal, float maxVal, float speed = 2) {
	static float startTime = -1.0f;
	if (startTime < 0.0f) {
		startTime = Time::time();
	}
	float currentTime = Time::time();
	float elapsedTime = math::fmod(currentTime - startTime, 2.0f / speed);
	if (elapsedTime < 1.0f / speed) {
		return minVal + elapsedTime * speed * (maxVal - minVal);
	}
	else {
		return maxVal - (elapsedTime - 1.0f / speed) * speed * (maxVal - minVal);
	}
}
namespace u_render {
	void texturebox(Vector2 startpos, Vector2 size, Color color, float radius = 0, float round = 0)
	{
		GUI::DrawTexture(Rect(startpos.x, startpos.y, size.x, size.y), (uintptr_t)Texture2D::whiteTexture(), 0, true, 0, color.ToUnity(), Vector4(radius, radius, radius, radius), Vector4(round, round, round, round), true);
	}
	void circle(Vector2 center, float radius, Color color, float radius2 = 1)
	{
		texturebox(Vector2(center.x - radius, center.y - radius), Vector2(radius * 2, radius * 2), color, radius2, radius);
	}
	void text(Vector2 pos, String text, Color clr = { 255.f, 255.f, 255.f, 255.f }, bool centered = false, float size = 10, bool outline = true, bool left = false , const wchar_t* font_name = _(L"museosanscyrl-700.ttf")) {
		
		if (!label || label < 0x10000 || !skin || skin < 0x10000) return;
		
		const auto set_font = [&](String font_name, int size) {
			
			if (!cheat_bundle) {
				crash_logger::log_error("text: cheat_bundle is NULL, cannot load font");
				return;
			}
			
			uintptr_t font = AssetBundle::LoadAsset_Internal(cheat_bundle, font_name, il2cpp::type_object(_("UnityEngine"), _("Font")));
			if (!font) {
				crash_logger::log_error("text: Failed to load font from bundle");
				return;
			}

			*rc<uintptr_t*>(skin + 0x18) = font;
			GUIStyle::fontsize(label, size);
		};
		
		if (font_name != _(L"") && cheat_bundle) {
			set_font(font_name, size);
		}
		const auto content = GUIContent::Temp(&text);
		if (left) {
			GUIStyle::alignment(label, 2);
			if (outline)
			{
				GUI::color({ 0, 0, 0, clr.a / 255 });
				GUI::Label({ pos.x - 500,  pos.y - 19,  pos.x,  pos.y }, content, label);
				GUI::Label({ pos.x - 499,  pos.y - 20,  pos.x,  pos.y }, content, label);
				GUI::Label({ pos.x - 500,  pos.y - 21,  pos.x,  pos.y }, content, label);
				GUI::Label({ pos.x - 501,  pos.y - 20,  pos.x,  pos.y }, content, label);
			}
			GUI::color(clr.ToUnity());
			GUI::Label({ pos.x - 500,  pos.y - 20,  pos.x,  pos.y }, content, label);
		}
		else {
			if (centered) {
				GUIStyle::alignment(label, 4);
				if (outline)
				{
					GUI::color({ 0, 0, 0, clr.a / 255 });
					GUI::Label({ pos.x - 250,  pos.y - 249,  500, 500 }, content, label);
					GUI::Label({ pos.x - 249,  pos.y - 250,  500, 500 }, content, label);
					GUI::Label({ pos.x - 250,  pos.y - 251,  500, 500 }, content, label);
					GUI::Label({ pos.x - 251,  pos.y - 250,  500, 500 }, content, label);
				}
				GUI::color(clr.ToUnity());
				GUI::Label({ pos.x - 250,  pos.y - 250,  500, 500 }, content, label);

			}
			else {
				GUIStyle::alignment(label, 0);
				if (outline)
				{
					GUI::color({ 0, 0, 0, clr.a / 255 });
					GUI::Label({ pos.x,  pos.y + 1,  500,  20 }, content, label);
					GUI::Label({ pos.x + 1,  pos.y,  500,  20 }, content, label);
					GUI::Label({ pos.x,  pos.y - 1,  500,  20 }, content, label);
					GUI::Label({ pos.x - 1,  pos.y,  500,  20 }, content, label);
				}
				GUI::color(clr.ToUnity());
				GUI::Label({ pos.x,  pos.y,  500,  20 }, content, label);
			}
		}
	}
	void get_draw_shader() {
		draw_shader = il2cpp::methods::object_new(il2cpp::init_class(_("Material"), _("UnityEngine")));
	}
	void gradient_box(Vector2 start, Vector2 end, Color col, Color col2, bool inverted = true) {
		if (!draw_shader) return get_draw_shader();
		GL::Begin(begin_mode::quads);
		if (inverted)
		{
			GL::Color(col.ToUnity());
			GL::Vertex({ start.x, start.y, 0 });
			GL::Vertex({ start.x + end.x, start.y, 0 });
			GL::Color(col2.ToUnity());
			GL::Vertex({ start.x + end.x, start.y + end.y, 0 });
			GL::Vertex({ start.x, start.y + end.y, 0 });
		}
		else
		{
			GL::Color(col.ToUnity());
			GL::Vertex({ start.x, start.y, 0 });
			GL::Vertex({ start.x, start.y + end.y, 0 });
			GL::Color(col2.ToUnity());
			GL::Vertex({ start.x + end.x, start.y + end.y, 0 });
			GL::Vertex({ start.x + end.x, start.y, 0 });
		}
		GL::End();
	}
	void InitializeAADrawing()
	{

		if (linetextureID == -1) return; 
		linetextureID = -1;
	}
	void drawline(Vector2 PointA, Vector2 PointB, Color clr, float Width, bool AntiAlias = true)
	{
		if (PointA == Vector2::Zero() || PointB == Vector2::Zero()) return;
		
		float DeltaX = PointB.x - PointA.x;
		float DeltaY = PointB.y - PointA.y;
		float Length = Mathf::Sqrt(DeltaX * DeltaX + DeltaY * DeltaY);
		
		if (Length < 0.01f) return;

		
		uintptr_t Texture = (uintptr_t)Texture2D::whiteTexture();
		if (!Texture || Texture < 0x10000) return; 
		
		if (AntiAlias) Width *= 3.f;

		float WidthDeltaX = Width * DeltaY / Length;
		float WidthDeltaY = Width * DeltaX / Length;

		Matrix4x4Line Matrix = Matrix4x4Line().Identity();
		Matrix.m00 = DeltaX;
		Matrix.m01 = -WidthDeltaX;
		Matrix.m03 = PointA.x + 0.5f * WidthDeltaX;
		Matrix.m10 = DeltaY;
		Matrix.m11 = WidthDeltaY;
		Matrix.m13 = PointA.y - 0.5f * WidthDeltaY;

		GL::PushMatrix();
		GL::MultMatrix(Matrix);
		GUI::color(clr.ToUnity());
		GUI::DrawTexture(Rect(0, 0, 1, 1), Texture);
		GL::PopMatrix();
	}
}