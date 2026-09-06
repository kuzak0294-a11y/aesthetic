namespace auto_co_ofsets {
	namespace ItemModProjectile {
		static auto GetRandomVelocity = rc<float(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("ItemModProjectile"), _("GetRandomVelocity"), 0, _(""), _(""))));
	}
	namespace String_ {
		static auto Contains = rc<bool(*)(String*, String*)>(*rc<uintptr_t*>(il2cpp::method(_("String"), _("Contains"), 1, _(""), _("System"))));
	}
	namespace Component {
		static auto get_component = rc<uintptr_t(*)(uintptr_t, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Component"), _("GetComponent"), 0, _(""), _("UnityEngine"))));
		static auto gameObject = rc<uintptr_t(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Component"), _("get_gameObject"), 0, _(""), _("UnityEngine"))));
		static auto transform = rc<uintptr_t(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Component"), _("get_transform"), 0, _(""), _("UnityEngine"))));
	}
	namespace BaseNetworkable {
		static auto HasParent = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseNetworkable"), _("HasParent"), 0, _(""), _(""))));
		static auto get_ShortPrefabName = rc<String * (*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseNetworkable"), _("get_ShortPrefabName"), 0, _(""), _(""))));
	}
	namespace BuildingBlock {
		static auto IsUpgradeBlocked = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BuildingBlock"), _("IsUpgradeBlocked"), 0, _(""), _(""))));
		static auto CanAffordUpgrade = rc<bool(*)(uintptr_t, BuildingGrade::Enum, int, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BuildingBlock"), _("CanAffordUpgrade"), 3, _(""), _(""))));
		static auto CanChangeToGrade = rc<bool(*)(uintptr_t, BuildingGrade::Enum, int, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BuildingBlock"), _("CanChangeToGrade"), 3, _(""), _(""))));
		static auto UpgradeToGrade = rc<bool(*)(uintptr_t, BuildingGrade::Enum, int, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BuildingBlock"), _("UpgradeToGrade"), 3, _(""), _(""))));
	}
	namespace EnvironmentManager {
		static auto Get = rc<uintptr_t(*)(Vector3, float)>(*rc<uintptr_t*>(il2cpp::method(_("EnvironmentManager"), _("Get"), 2, _(""), _(""))));
	}
	namespace PlayerModel {
		static auto RebuildAll = rc<void(*)()>(*rc<uintptr_t*>(il2cpp::method(_("PlayerModel"), _("RebuildAll"), 0, _(""), _(""))));
	}
	namespace Transform {
		static auto position = rc<Vector3(*)(uintptr_t self)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("get_position"), 0, _(""), _("UnityEngine"))));
		static auto get_localToWorldMatrix = rc<Matrix4x4(*)(uintptr_t self)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("get_localToWorldMatrix"), 0, _(""), _("UnityEngine"))));
		static auto set_position = rc<void(*)(uintptr_t self, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("set_position"), 1, _(""), _("UnityEngine"))));
		static auto get_localPosition = rc<Vector3(*)(uintptr_t self)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("get_localPosition"), 0, _(""), _("UnityEngine"))));
		static auto set_localPosition = rc<void(*)(uintptr_t self, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("set_localPosition"), 1, _(""), _("UnityEngine"))));
		static auto get_up = rc<Vector3(*)(uintptr_t self)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("get_up"), 0, _(""), _("UnityEngine"))));
		static auto set_rotation = rc<void(*)(uintptr_t self, Vector4)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("set_rotation"), 1, _(""), _("UnityEngine"))));
		static auto get_rotation = rc<Vector4(*)(uintptr_t self)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("get_rotation"), 0, _(""), _("UnityEngine"))));
		static auto set_localScale = rc<void(*)(uintptr_t self, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("set_localScale"), 1, _(""), _("UnityEngine"))));
		static auto InverseTransformPoint = rc<Vector3(*)(uintptr_t self, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("InverseTransformPoint"), 1, _(""), _("UnityEngine"))));
		static auto InverseTransformDirection = rc<Vector3(*)(uintptr_t self, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("InverseTransformDirection"), 1, _(""), _("UnityEngine"))));
	}
	namespace HitInfo {
		static auto PositionOnRay = rc<Vector3(*)(uintptr_t, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("HitInfo"), _("PositionOnRay"), 2, _(""), _(""))));
		static auto LoadFromAttack = rc<void(*)(uintptr_t, uintptr_t, bool)>(*rc<uintptr_t*>(il2cpp::method(_("HitInfo"), _("LoadFromAttack"), 3, _(""), _(""))));
	}
	namespace Material {
		static auto get_name = rc<String * (*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Object"), _("get_name"), 0, _(""), _("UnityEngine"))));
		static auto getshader = rc<uintptr_t(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Material"), _("get_shader"), 0, _(""), _("UnityEngine"))));
		static auto set_shader = rc<void(*)(uintptr_t, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Material"), _("set_shader"), 1, _(""), _("UnityEngine"))));
		static auto SetInt = rc<void(*)(uintptr_t, String*, int)>(*rc<uintptr_t*>(il2cpp::method(_("Material"), _("SetInt"), 2, _(""), _("UnityEngine"))));
		static auto SetFloat = rc<void(*)(uintptr_t, String*, float)>(*rc<uintptr_t*>(il2cpp::method(_("Material"), _("SetFloat"), 2, _(""), _("UnityEngine"))));
		static auto set_renderQueue = rc<void(*)(uintptr_t, int)>(*rc<uintptr_t*>(il2cpp::method(_("Material"), _("set_renderQueue"), 1, _(""), _("UnityEngine"))));
		static auto SetColor = rc<void(*)(uintptr_t, String*, Color)>(*rc<uintptr_t*>(il2cpp::method(_("Material"), _("SetColor"), 2, _(""), _("UnityEngine"))));
	}
	namespace Renderer {
		static auto get_material = rc<uintptr_t(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Renderer"), _("get_material"), 0, _(""), _("UnityEngine"))));
		static auto set_material = rc<void(*)(uintptr_t, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Renderer"), _("set_material"), 1, _(""), _("UnityEngine"))));
	}
	namespace HitTest {
		static auto BuildAttackMessage = rc<uintptr_t(*)(uintptr_t, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("HitTest"), _("BuildAttackMessage"), 2, _(""), _(""))));
		static auto HitPointWorld = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("HitTest"), _("HitPointWorld"), 0, _(""), _(""))));
		static auto HitNormalWorld = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("HitTest"), _("HitNormalWorld"), 0, _(""), _(""))));
	}
	namespace PlayerInventory {
		static auto HasAmmo = rc<bool(*)(uintptr_t, AmmoTypes)>(*rc<uintptr_t*>(il2cpp::method(_("PlayerInventory"), _("HasAmmo"), 1, _(""), _(""))));
	}
	namespace Random {
		static auto RandomRange = rc<float(*)(float min, float max)>(*rc<uintptr_t*>(il2cpp::method(_("Random"), _("RandomRange"), 0, _(""), _("UnityEngine"))));
	}
	namespace Mathx {
		static auto Increment = rc<float(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Mathx"), _("Increment"), 1, _(""), _(""))));
		static auto Decrement = rc<float(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Mathx"), _("Decrement"), 1, _(""), _(""))));
		static auto Max = rc<float(*)(float f1, float f2, float f3)>(*rc<uintptr_t*>(il2cpp::method(_("Mathx"), _("Max"), 0, _(""), _(""))));
	}
	namespace Mathf {
		static auto Abs = rc<float(*)(float x)>(*rc<uintptr_t*>(il2cpp::method(_("Mathf"), _("Abs"), 1, _(""), _("UnityEngine"))));
		static auto Sin = rc<float(*)(float f)>(*rc<uintptr_t*>(il2cpp::method(_("Mathf"), _("Sin"), 1, _(""), _("UnityEngine"))));
		static auto Cos = rc<float(*)(float f)>(*rc<uintptr_t*>(il2cpp::method(_("Mathf"), _("Cos"), 1, _(""), _("UnityEngine"))));
		static auto Tan = rc<float(*)(float f)>(*rc<uintptr_t*>(il2cpp::method(_("Mathf"), _("Tan"), 1, _(""), _("UnityEngine"))));

		static auto Atan2 = rc<float(*)(float y, float x)>(*rc<uintptr_t*>(il2cpp::method(_("Mathf"), _("Atan2"), 2, _(""), _("UnityEngine"))));
		static auto Clamp = rc<float(*)(float value, float min, float max)>(*rc<uintptr_t*>(il2cpp::method(_("Mathf"), _("Clamp"), 3, _(""), _("UnityEngine"))));
		static auto Sqrt = rc<float(*)(float f)>(*rc<uintptr_t*>(il2cpp::method(_("Mathf"), _("Sqrt"), 1, _(""), _("UnityEngine"))));
		static auto Lerp = rc<float(*)(float a, float b, float t)>(*rc<uintptr_t*>(il2cpp::method(_("Mathf"), _("Lerp"), 3, _(""), _("UnityEngine"))));
	}
	namespace MainCamera {
		static auto get_position = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("MainCamera"), _("get_position"), 0, _(""), _(""))));
		static auto get_rotation = rc<Quaternion(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("MainCamera"), _("get_rotation"), 0, _(""), _(""))));
		static auto get_forward = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("MainCamera"), _("get_forward"), 0, _(""), _(""))));
	}
	namespace Time {
		static auto time = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_time"), 0, _(""), _("UnityEngine"))));
		static auto deltaTime = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_deltaTime"), 0, _(""), _("UnityEngine"))));
		static auto fixedTime = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_fixedTime"), 0, _(""), _("UnityEngine"))));
		static auto unscaledTime = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_unscaledTime"), 0, _(""), _("UnityEngine"))));
		static auto unscaledDeltaTime = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_unscaledDeltaTime"), 0, _(""), _("UnityEngine"))));
		static auto fixedDeltaTime = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_fixedDeltaTime"), 0, _(""), _("UnityEngine"))));
		static auto maximumDeltaTime = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_maximumDeltaTime"), 0, _(""), _("UnityEngine"))));
		static auto smoothDeltaTime = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_smoothDeltaTime"), 0, _(""), _("UnityEngine"))));
		static auto timeScale = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_timeScale"), 0, _(""), _("UnityEngine"))));
		static auto frameCount = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_frameCount"), 0, _(""), _("UnityEngine"))));
		static auto renderedFrameCount = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_renderedFrameCount"), 0, _(""), _("UnityEngine"))));
		static auto realtimeSinceStartup = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_realtimeSinceStartup"), 0, _(""), _("UnityEngine"))));
	}
	namespace GamePhysics {
		static auto LineOfSight = rc<bool(*)(Vector3 p0, Vector3 p1, int layerMask, uintptr_t ignoreEntity)>(*rc<uintptr_t*>(il2cpp::method(_("GamePhysics"), _("LineOfSight"), 4, _(""), _(""))));
		static auto LineOfSightRadius = rc<bool(*)(Vector3, Vector3, int, float, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("GamePhysics"), _("LineOfSightRadius"), 5, _(""), _(""))));
		static auto Trace = rc<bool(*)(Ray, float, RaycastHit, float, int, QueryTriggerInteraction, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("GamePhysics"), _("Trace"), 7, _(""), _(""))));
	}
	namespace Physics {
		static auto Raycast = rc<bool(*)(Ray, RaycastHit, float, int, QueryTriggerInteraction)>(*rc<uintptr_t*>(il2cpp::method(_("Physics"), _("Raycast"), 5, _(""), _("UnityEngine"))));
		static auto Raycast2 = rc<bool(*)(Vector3, Vector3, float, int, QueryTriggerInteraction)>(*rc<uintptr_t*>(il2cpp::method(_("Physics"), _("Raycast"), 5, _(""), _("UnityEngine"))));
		static auto CheckCapsule = rc<bool(*)(Vector3, Vector3, float, int, QueryTriggerInteraction)>(*rc<uintptr_t*>(il2cpp::method(_("Physics"), _("CheckCapsule"), 5, _(""), _("UnityEngine"))));
		static auto gravity = rc<Vector3(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Physics"), _("get_gravity"), 0, _(""), _("UnityEngine"))));
	}
	namespace Shader {
		static auto Find = rc<uintptr_t(*)(String)>(*rc<uintptr_t*>(il2cpp::method(_("Shader"), _("Find"), 1, _(""), _("UnityEngine"))));
		static auto get_passCount = rc<int(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Shader"), _("get_passCount"), 0, _(""), _("UnityEngine"))));
	}
	namespace GameManifest {
		static auto GUIDToObject = rc<uintptr_t(*)(String*)>(*rc<uintptr_t*>(il2cpp::method(_("GameManifest"), _("GUIDToObject"), 1, _(""), _(""))));
	}

	namespace GameObject {
		static auto Internal_CreateGameObject = rc<void(*)(uintptr_t self, String shader)>(*rc<uintptr_t*>(il2cpp::method(_("GameObject"), _("Internal_CreateGameObject"), 2, _(""), _("UnityEngine"))));
		static auto GetComponent = rc<uintptr_t(*)(uintptr_t self, uintptr_t type)>(*rc<uintptr_t*>(il2cpp::method(_("GameObject"), _("GetComponent"), 1, _(""), _("UnityEngine"))));
		static auto Internal_AddComponentWithType = rc<void(*)(uintptr_t self, uintptr_t componentType)>(*rc<uintptr_t*>(il2cpp::method(_("GameObject"), _("Internal_AddComponentWithType"), 1, _(""), _("UnityEngine"))));
	}
	namespace Object {
		static auto DontDestroyOnLoad = rc<void(*)(uintptr_t target)>(*rc<uintptr_t*>(il2cpp::method(_("Object"), _("DontDestroyOnLoad"), 1, _(""), _("UnityEngine"))));
		static auto FindObjectFromInstanceID = rc<uintptr_t(*)(int instanceID)>(*rc<uintptr_t*>(il2cpp::method(_("Object"), _("FindObjectFromInstanceID"), 1, _(""), _("UnityEngine"))));
		static auto GetInstanceID = rc<int(*)(uintptr_t target)>(*rc<uintptr_t*>(il2cpp::method(_("Object"), _("GetInstanceID"), 0, _(""), _("UnityEngine"))));
	}
	namespace Event {
		static auto get_current = rc<uintptr_t(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Event"), _("get_current"), 0, _(""), _("UnityEngine"))));
		static auto get_type = rc<EventType(*)(uintptr_t self)>(*rc<uintptr_t*>(il2cpp::method(_("Event"), _("get_type"), 0, _(""), _("UnityEngine"))));
		static auto get_keyCode = rc<KeyCode(*)(uintptr_t self)>(*rc<uintptr_t*>(il2cpp::method(_("Event"), _("get_keyCode"), 0, _(""), _("UnityEngine"))));
	}
	namespace GUI {
		static auto Label = rc<void(*)(Rect position, uintptr_t content, uintptr_t style)>(*rc<uintptr_t*>(il2cpp::method(_("GUI"), _("Label"), 3, _("content"), _("UnityEngine"), 2)));
		static auto get_skin = rc<uintptr_t(*)()>(*rc<uintptr_t*>(il2cpp::method(_("GUI"), _("get_skin"), 0, _(""), _("UnityEngine"))));
		static auto set_color = rc<void(*)(Color color)>(*rc<DWORD64*>(il2cpp::method(_("GUI"), _("set_color"), 1, _(""), _("UnityEngine"))));
		static auto DrawTexture = rc<void (*)(Rect position, uintptr_t image, uintptr_t scaleMode, bool alphaBlend, float imageAspect, Color color, Vector4 borderWidths, Vector4 borderRadiuses, bool drawSmoothCorners)>(*rc<uintptr_t*>(il2cpp::method(_("GUI"), _("DrawTexture"), 9, _("image"), _("UnityEngine"), 2)));
		static auto DrawTexture_min = rc<void (*)(Rect, uintptr_t)>(*rc<DWORD64*>(il2cpp::method(_("GUI"), _("DrawTexture"), 2, _("image"), _("UnityEngine"), 2)));
	}
	namespace AssetBundle {
		static auto Unload = rc<void(*)(uintptr_t, bool)>(*rc<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("Unload"), 1, _(""), _("UnityEngine"))));
		static auto LoadFromFile = rc<uintptr_t(*)(String path)>(*rc<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("LoadFromFile"), 1, _("path"), _("UnityEngine"), 1)));
		static auto LoadAsset_Internal = rc<uintptr_t(*)(uintptr_t self, String path, uintptr_t type)>(*rc<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("LoadAsset_Internal"), 2, _("name"), _("UnityEngine"), 1)));
		static auto LoadAsset = rc<uintptr_t(*)(uintptr_t bundle, String path, uintptr_t type)>(*rc<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("LoadAsset"), 2, _("name"), _("UnityEngine"), 1)));
	}
	namespace Networkable {
		static auto get_components_in_children = rc<uintptr_t(*)(uintptr_t, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Component"), _("GetComponentsInChildren"), 0, _(""), _("UnityEngine"))));
	}
	namespace GL {
		static auto PushMatrix = rc<void(*)()>(*rc<DWORD64*>(il2cpp::method(_("GL"), _("PushMatrix"), 0, _(""), _("UnityEngine"))));
		static auto MultMatrix = rc<void(*)(Matrix4x4Line)>(*rc<DWORD64*>(il2cpp::method(_("GL"), _("MultMatrix"), 0, _(""), _("UnityEngine"))));
		static auto PopMatrix = rc<void(*)()>(*rc<DWORD64*>(il2cpp::method(_("GL"), _("PopMatrix"), 0, _(""), _("UnityEngine"))));

		static auto Begin = rc<void(*)(int mode)>(*rc<uintptr_t*>(il2cpp::method(_("GL"), _("Begin"), 0, _(""), _("UnityEngine"))));
		static auto Color_ = rc<void(*)(Color color)>(*rc<uintptr_t*>(il2cpp::method(_("GL"), _("Color"), 0, _(""), _("UnityEngine"))));
		static auto Vertex = rc<void(*)(Vector3 v)>(*rc<uintptr_t*>(il2cpp::method(_("GL"), _("Vertex"), 0, _(""), _("UnityEngine"))));
		static auto End = rc<void(*)()>(*rc<uintptr_t*>(il2cpp::method(_("GL"), _("End"), 0, _(""), _("UnityEngine"))));
	}
	namespace GUIStyle {
		static auto set_alignment = rc<void(*)(uintptr_t label, uintptr_t value)>(*rc<uintptr_t*>(il2cpp::method(_("GUIStyle"), _("set_alignment"), 1, _(""), _("UnityEngine"))));
		static auto set_fontsize = rc<void(*)(uintptr_t label, int size)>(*rc<uintptr_t*>(il2cpp::method(_("GUIStyle"), _("set_fontSize"), 1, _(""), _("UnityEngine"))));
		static auto set_font = rc<void(*)(uintptr_t label, uintptr_t font)>(*rc<uintptr_t*>(il2cpp::method(_("GUIStyle"), _("set_font"), 1, _(""), _("UnityEngine"))));
	}
	namespace ItemDefinition {
		static auto GetDisplayName = rc<uintptr_t(*)(uintptr_t self, uintptr_t item)>(*rc<uintptr_t*>(il2cpp::method(_("ItemDefinition"), _("GetDisplayName"), 1, _(""), _(""))));
	}
	namespace GUIContent {
		static auto Temp = rc<uintptr_t(*)(String * t)>(*rc<uintptr_t*>(il2cpp::method(_("GUIContent"), _("Temp"), 1, _("t"), _("UnityEngine"), 1)));
	}
	namespace Input {
		static auto GetMouseButton = rc<bool(*)(int button)>(*rc<uintptr_t*>(il2cpp::method(_("Input"), _("GetMouseButton"), 1, _(""), _("UnityEngine"))));
		static auto get_mousePosition = rc<Vector2(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Input"), _("get_mousePosition"), 0, _(""), _("UnityEngine"))));
		static auto GetAxis = rc<float(*)(String axisName)>(*rc<uintptr_t*>(il2cpp::method(_("Input"), _("GetAxis"), 1, _(""), _("UnityEngine"))));
		static auto GetKey = rc<bool(*)(KeyCode name)>(*rc<uintptr_t*>(il2cpp::method(_("Input"), _("GetKey"), 1, _(""), _("UnityEngine"))));
		static auto GetKeyInt = rc<bool(*)(KeyCode)>(*rc<uintptr_t*>(il2cpp::method(_("Input"), _("GetKeyInt"), 1, _(""), _("UnityEngine"))));
	}
	namespace Screen {
		static auto get_height = rc<int(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Screen"), _("get_height"), 0, _(""), _("UnityEngine"))));
		static auto get_width = rc<int(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Screen"), _("get_width"), 0, _(""), _("UnityEngine"))));
	}
	namespace InputState {
		static auto WasJustPressed = rc<bool(*)(uintptr_t, BUTTON)>(*rc<uintptr_t*>(il2cpp::method(_("InputState"), _("WasJustPressed"), 1, _(""), _(""))));
	}
	namespace BaseEntity {
		static auto IsOutside = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("IsOutside"), 0, _(""), _(""))));
		static auto MaxVelocity = rc<float(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("MaxVelocity"), 0, _(""), _(""))));
		static auto GetParentVelocity = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("GetParentVelocity"), 0, _(""), _(""))));
		static auto BoundsPadding = rc<float(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("BoundsPadding"), 0, _(""), _(""))));
		static auto HasFlag = rc<bool(*)(uintptr_t, baseent_Flags)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("HasFlag"), 1, _(""), _(""))));
		static auto SendSignalBroadcast = rc<bool(*)(uintptr_t, Signal, String)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("SendSignalBroadcast"), 2, _(""), _(""))));
		static auto CenterPoint = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("CenterPoint"), 0, _(""), _(""))));
		static auto GetWorldVelocity = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("GetWorldVelocity"), 0, _(""), _(""))));
		static auto Distance = rc<float(*)(uintptr_t, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("Distance"), 2, _(""), _(""))));
		static auto ServerRPC = rc<void(*)(uintptr_t, String)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("ServerRPC"), 1, _("funcName"), _(""), 1)));
		static auto ServerRPC4 = rc<void(*)(uintptr_t, String, Vector3, Vector3, bool)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("ServerRPC"), 4, _("funcName"), _(""), 1)));
	}
	namespace Rigidbody {
		static auto get_velocity = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Rigidbody"), _("get_velocity"), 0, _(""), _("UnityEngine"))));
		static auto set_velocity = rc<void(*)(uintptr_t, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("Rigidbody"), _("set_velocity"), 1, _(""), _("UnityEngine"))));
	}
	namespace AimConeUtil {
		static auto GetModifiedAimConeDirection = rc<Vector3(*)(float, Vector3, bool)>(*rc<uintptr_t*>(il2cpp::method(_("AimConeUtil"), _("GetModifiedAimConeDirection"), 3, _(""), _(""))));
	}
	namespace Texture2D {
		static auto get_whiteTexture = rc<uintptr_t(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Texture2D"), _("get_whiteTexture"), 0, _(""), _("UnityEngine"))));
		static auto SetPixel = rc<void(*)(uintptr_t target, int x, int y, Color color)>(*rc<uintptr_t*>(il2cpp::method(_("Texture2D"), _("SetPixel"), 3, _(""), _("UnityEngine"))));
		static auto Apply = rc<void(*)(uintptr_t target, bool updateMipmaps)>(*rc<uintptr_t*>(il2cpp::method(_("Texture2D"), _("Apply"), 1, _(""), _("UnityEngine"))));
		static auto Internal_Create = rc<void(*)(uintptr_t mono, int w, int h, int mipCount, int format, int colorSpace, int flags, __int64 nativeTex, String mipmapLimitGroupName)>(*rc<uintptr_t*>(il2cpp::method(_("Texture2D"), _("Internal_Create"), 9, _(""), _("UnityEngine"))));
		static auto get_isReadable = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Texture2D"), _("get_isReadable"), 0, _(""), _("UnityEngine"))));
	}
	namespace DamageTypeList {
		static auto Scale = rc<void(*)(uintptr_t, DamageType, bool)>(*rc<uintptr_t*>(il2cpp::method(_("DamageTypeList"), _("Scale"), 2, _(""), _("Rust"))));
		static auto Total = rc<float(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("DamageTypeList"), _("Total"), 0, _(""), _("Rust"))));
	}
	namespace BaseMovement {
		static auto get_TargetMovement = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseMovement"), _("get_TargetMovement"), 0, _(""), _(""))));
		static auto set_TargetMovement = rc<void(*)(uintptr_t, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("BaseMovement"), _("set_TargetMovement"), 1, _(""), _(""))));
		static auto TeleportTo = rc<void(*)(uintptr_t, Vector3, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseMovement"), _("TeleportTo"), 2, _(""), _(""))));
	}


	namespace TerrainHeightMap {
		static auto GetNormal = rc<Vector3(*)(uintptr_t, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("TerrainHeightMap"), _("GetNormal"), 0, _(""), _(""))));
		static auto GetHeight = rc<float(*)(uintptr_t, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("TerrainHeightMap"), _("GetHeight"), 0, _(""), _(""))));
	}
	namespace Terrain {
		static auto SampleHeight = rc<float(*)(uintptr_t, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("Terrain"), _("SampleHeight"), 1, _("worldPosition"), _("UnityEngine"), 1)));
	}
	namespace TerrainCollision {
		static auto GetIgnore = rc<bool(*)(uintptr_t, Vector3, float)>(*rc<uintptr_t*>(il2cpp::method(_("TerrainCollision"), _("GetIgnore"), 2, _(""), _(""))));
	}
	namespace TerrainMeta {
		static auto get_Position = rc<Vector3(*)(DWORD64)>(*rc<uintptr_t*>(il2cpp::method(_("TerrainMeta"), _("get_Position"), 0, _(""), _(""))));
		static auto get_HeightMap = rc<uintptr_t(*)(DWORD64)>(*rc<uintptr_t*>(il2cpp::method(_("TerrainMeta"), _("get_HeightMap"), 0, _(""), _(""))));
		static auto get_Terrain = rc<uintptr_t(*)(DWORD64)>(*rc<uintptr_t*>(il2cpp::method(_("TerrainMeta"), _("get_Terrain"), 0, _(""), _(""))));
		static auto get_Collision = rc<uintptr_t(*)(DWORD64)>(*rc<uintptr_t*>(il2cpp::method(_("TerrainMeta"), _("get_Collision"), 0, _(""), _(""))));
	}
	namespace GameTrace {
		static auto TraceAll = rc<bool(*)(uintptr_t, uintptr_t, int)>(*rc<uintptr_t*>(il2cpp::method(_("GameTrace"), _("TraceAll"), 3, _(""), _(""))));
	}
	namespace DDraw {
		static auto Text = rc<void(*)(String*, Vector3, Color, float, float, bool)>(*rc<uintptr_t*>(il2cpp::method(_("DDraw"), _("Text"), 6, _(""), _("UnityEngine"))));
		static auto Line = rc<void(*)(Vector3, Vector3, Color, float, bool, bool)>(*rc<uintptr_t*>(il2cpp::method(_("DDraw"), _("Line"), 6, _(""), _("UnityEngine"))));
		static auto Capsule = rc<void(*)(Vector3, Quaternion, float, float, Color, float, bool, bool)>(*rc<uintptr_t*>(il2cpp::method(_("DDraw"), _("Capsule"), 8, _(""), _("UnityEngine"))));
		static auto Sphere = rc<void(*)(Vector3, float, Color, float, bool, bool)>(*rc<uintptr_t*>(il2cpp::method(_("DDraw"), _("Sphere"), 6, _(""), _("UnityEngine"))));
	}
	namespace AssetNameCache {
		static auto GetName = rc<String * (*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("AssetNameCache"), _("GetName"), 1, _(""), _(""))));
	}
	namespace Projectile {
		static auto get_isAuthoritative = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Projectile"), _("get_isAuthoritative"), 0, _(""), _(""))));
		static auto get_isAlive = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Projectile"), _("get_isAlive"), 0, _(""), _(""))));
		static auto DoHit = rc<bool(*)(uintptr_t, uintptr_t, Vector3, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("Projectile"), _("DoHit"), 3, _(""), _(""))));
		static auto Launch = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Projectile"), _("Launch"), 0, _(""), _(""))));
		static auto SetEffectScale = rc<void(*)(uintptr_t, float)>(*rc<uintptr_t*>(il2cpp::method(_("Projectile"), _("SetEffectScale"), 1, _(""), _(""))));
		static auto UpdateVelocity = rc<void(*)(uintptr_t, float)>(*rc<uintptr_t*>(il2cpp::method(_("Projectile"), _("UpdateVelocity"), 1, _(""), _(""))));
		static auto Retire = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Projectile"), _("Retire"), 0, _(""), _(""))));
		static auto CalculateEffectScale = rc<float(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Projectile"), _("CalculateEffectScale"), 0, _(""), _(""))));
		static auto DoFlybySound = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Projectile"), _("DoFlybySound"), 0, _(""), _(""))));
		static auto get_transform = rc<uintptr_t(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Component"), _("get_transform"), 0, _(""), _("UnityEngine"))));
	}
	namespace ItemIcon {
		static auto RunTimedAction = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("ItemIcon"), _("RunTimedAction"), 0, _(""), _(""))));
	}
	namespace PlayerWalkMovement {
		static auto Jump = rc<void(*)(uintptr_t, uintptr_t, bool)>(*rc<uintptr_t*>(il2cpp::method(_("PlayerWalkMovement"), _("Jump"), 2, _(""), _(""))));
	}
	namespace SkinnedMultiMesh {
		static auto get_Renderers = rc<List<Renderer_*>*(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("SkinnedMultiMesh"), _("get_Renderers"), 0, _(""), _(""))));
	}
	namespace ModelState {
		static auto set_ducked = rc<void(*)(uintptr_t, bool)>(*rc<uintptr_t*>(il2cpp::method(_("ModelState"), _("set_ducked"), 1, _(""), _(""))));
		static auto set_jumped = rc<void(*)(uintptr_t, bool)>(*rc<uintptr_t*>(il2cpp::method(_("ModelState"), _("set_jumped"), 1, _(""), _(""))));
	}
	namespace HeldEntity {
		static auto GetFovOverride = rc<float(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("HeldEntity"), _("GetFovOverride"), 0, _(""), _(""))));
	}
	namespace MetalDetectorSource {
		static auto get_SpawnLocations = rc<List<Vector3>*(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("MetalDetectorSource"), _("get_SpawnLocations"), 0, _(""), _(""))));
	}
	namespace AttackEntity {
		static auto CalculateCooldownTime = rc<float(*)(uintptr_t, float, float, bool)>(*rc<uintptr_t*>(il2cpp::method(_("AttackEntity"), _("CalculateCooldownTime"), 3, _(""), _(""))));
		static auto StartAttackCooldown = rc<void(*)(uintptr_t, float)>(*rc<uintptr_t*>(il2cpp::method(_("AttackEntity"), _("StartAttackCooldown"), 1, _(""), _(""))));
		static auto GetInheritedVelocity = rc<Vector3(*)(uintptr_t, uintptr_t, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("AttackEntity"), _("GetInheritedVelocity"), 2, _(""), _(""))));
		static auto HasAttackCooldown = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("AttackEntity"), _("HasAttackCooldown"), 0, _(""), _(""))));
		static auto GetAttackCooldown = rc<float(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("AttackEntity"), _("GetAttackCooldown"), 0, _(""), _(""))));
	}
	namespace BaseProjectile {
		static auto LaunchProjectile = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("LaunchProjectile"), 0, _(""), _(""))));
		static auto GetProjectileVelocityScale = rc<float(*)(uintptr_t, bool)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("GetProjectileVelocityScale"), 1, _(""), _(""))));
		static auto IsSilenced = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("IsSilenced"), 0, _(""), _(""))));
		static auto ShotFired = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("ShotFired"), 0, _(""), _(""))));
		static auto BeginCycle = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("BeginCycle"), 0, _(""), _(""))));
		static auto DoAttack = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("DoAttack"), 0, _(""), _(""))));
		static auto UpdateAmmoDisplay = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("UpdateAmmoDisplay"), 0, _(""), _(""))));
		static auto DidAttackClientside = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("DidAttackClientside"), 0, _(""), _(""))));
		static auto StartReloadCooldown = rc<void(*)(uintptr_t, float)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("StartReloadCooldown"), 1, _(""), _(""))));
		static auto GetReloadDuration = rc<float(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("GetReloadDuration"), 0, _(""), _(""))));
		static auto GetAvailableAmmo = rc<int(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("GetAvailableAmmo"), 0, _(""), _(""))));
	}
	namespace Sprite {
		static auto get_texture = rc<uintptr_t(*)(DWORD64)>(*rc<uintptr_t*>(il2cpp::method(_("Sprite"), _("get_texture"), 0, _(""), _("UnityEngine"))));
	}
	namespace RenderSettings {
		static auto set_ambientMode = rc<void(*)(AmbientMode)>(*rc<uintptr_t*>(il2cpp::method(_("RenderSettings"), _("set_ambientMode"), 1, _(""), _("UnityEngine"))));
		static auto set_ambientIntensity = rc<void(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("RenderSettings"), _("set_ambientIntensity"), 1, _(""), _("UnityEngine"))));
		static auto set_ambientLight = rc<void(*)(Color)>(*rc<uintptr_t*>(il2cpp::method(_("RenderSettings"), _("set_ambientLight"), 1, _(""), _("UnityEngine"))));
		static auto set_skybox = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("RenderSettings"), _("set_skybox"), 1, _(""), _("UnityEngine"))));
	}
	namespace Weather {
		static auto set_atmosphere_rayleigh = rc<void(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Weather"), _("set_atmosphere_rayleigh"), 1, _(""), _("ConVar"))));
		static auto set_atmosphere_mie = rc<void(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Weather"), _("set_atmosphere_mie"), 1, _(""), _("ConVar"))));
		static auto set_atmosphere_brightness = rc<void(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Weather"), _("set_atmosphere_brightness"), 1, _(""), _("ConVar"))));
		static auto set_cloud_opacity = rc<void(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Weather"), _("set_cloud_opacity"), 1, _(""), _("ConVar"))));
		static auto set_atmosphere_contrast = rc<void(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Weather"), _("set_atmosphere_contrast"), 1, _(""), _("ConVar"))));
		static auto set_fog = rc<void(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Weather"), _("set_fog"), 1, _(""), _("ConVar"))));
		static auto set_rain = rc<void(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Weather"), _("set_rain"), 1, _(""), _("ConVar"))));
		static auto set_thunder = rc<void(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Weather"), _("set_thunder"), 1, _(""), _("ConVar"))));
		static auto set_wind = rc<void(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Weather"), _("set_wind"), 1, _(""), _("ConVar"))));
	}
	namespace Item {
		static auto get_isBroken = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Item"), _("get_isBroken"), 0, _(""), _(""))));
		static auto get_iconSprite = rc<DWORD64(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Item"), _("get_iconSprite"), 0, _(""), _(""))));
	}
	namespace PlayerEyes {
		static auto get_position = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("PlayerEyes"), _("get_position"), 0, _(""), _(""))));
		static auto get_center = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("PlayerEyes"), _("get_center"), 0, _(""), _(""))));
		static auto BodyForward = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("PlayerEyes"), _("BodyForward"), 0, _(""), _(""))));
		static auto get_rotation = rc<Quaternion(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("PlayerEyes"), _("get_rotation"), 0, _(""), _(""))));
	}
	namespace BaseViewModel {
		static auto get_activemodel = rc<uintptr_t(*)()>(*rc<uintptr_t*>(il2cpp::method(_("BaseViewModel"), _("get_ActiveModel"), 0, _(""), _(""))));
	}
	namespace LocalPlayer {
		static auto ItemCommand = rc<void(*)(unsigned int, String)>(*rc<uintptr_t*>(il2cpp::method(_("LocalPlayer"), _("ItemCommand"), 2, _(""), _(""))));
	}
	namespace RandomUsernames {
		static auto Get1 = rc<String * (*)(uintptr_t, int)>(*rc<uintptr_t*>(il2cpp::method(_("RandomUsernames"), _("Get"), 1, _(""), _("Facepunch"))));
		static auto Get2 = rc<String * (*)(uintptr_t, uint64_t)>(*rc<uintptr_t*>(il2cpp::method(_("RandomUsernames"), _("Get"), 1, _(""), _("Facepunch"))));
	}
	namespace SteamPlatform {
		static auto get_UserName = rc<String * (*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("SteamPlatform"), _("get_UserName"), 0, _(""), _("Rust.Platform.Steam"))));
		static auto set_UserName = rc<void(*)(uintptr_t, String*)>(*rc<uintptr_t*>(il2cpp::method(_("SteamPlatform"), _("set_UserName"), 1, _(""), _("Rust.Platform.Steam"))));
	}
	namespace StashContainer {
		static auto IsHidden = rc<bool(*)()>(*rc<uintptr_t*>(il2cpp::method(_("StashContainer"), _("IsHidden"), 0, _(""), _(""))));
	}
	namespace BaseMelee {
		static auto get_CanAttack = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseMelee"), _("get_CanAttack"), 0, _(""), _(""))));
		static auto get_CanThrow = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseMelee"), _("get_CanThrow"), 0, _(""), _(""))));
		static auto DoAttack = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseMelee"), _("DoAttack"), 0, _(""), _(""))));
		static auto DoThrow = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseMelee"), _("DoThrow"), 0, _(""), _(""))));
		static auto ProcessAttack = rc<void(*)(uintptr_t, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseMelee"), _("ProcessAttack"), 1, _(""), _(""))));
	}
	namespace WaterLevel {
		static auto Test = rc<bool(*)(Vector3, bool, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("WaterLevel"), _("Test"), 3, _(""), _(""))));
		static auto GetWaterDepth = rc<float(*)(Vector3, bool, bool, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("WaterLevel"), _("GetWaterDepth"), 4, _(""), _(""))));
	}
	namespace BasePlayer {
		static auto ScaleDamage = rc<void(*)(uintptr_t, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("ScaleDamage"), 1, _(""), _(""))));
		static auto IsRunning = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("IsRunning"), 0, _(""), _(""))));
		static auto IsDucked = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("IsDucked"), 0, _(""), _(""))));
		static auto IsSwimming = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("IsSwimming"), 0, _(""), _(""))));
		static auto IsCrawling = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("IsCrawling"), 0, _(""), _(""))));
		static auto GetSpeed = rc<float(*)(uintptr_t, float, float, float)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetSpeed"), 3, _(""), _(""))));
		static auto OnLand = rc<void(*)(uintptr_t, float)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("OnLand"), 1, _("fVelocity"), _(""), 1)));
		static auto GetMounted = rc<DWORD64(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetMounted"), 0, _(""), _(""))));
		static auto ForcePositionTo = rc<void(*)(uintptr_t, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("ForcePositionTo"), 0, _(""), _(""))));
		static auto WorldSpaceBounds = rc<OBB(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("WorldSpaceBounds"), 0, _(""), _(""))));
		static auto ClosestPoint = rc<Vector3(*)(uintptr_t, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("ClosestPoint"), 2, _(""), _(""))));
		static auto PivotPoint = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("PivotPoint"), 0, _(""), _(""))));
		static auto GetMaxSpeed = rc<float(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetMaxSpeed"), 0, _(""), _(""))));
		static auto GetHeight = rc<float(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetHeight"), 0, _(""), _(""))));
		static auto GetHeldItem = rc<uintptr_t(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetHeldItem"), 0, _(""), _(""))));
		static auto NewProjectileID = rc<int(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("NewProjectileID"), 0, _(""), _(""))));
		static auto NewProjectileSeed = rc<int(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("NewProjectileSeed"), 0, _(""), _(""))));
		static auto OnLadder = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("OnLadder"), 0, _(""), _(""))));
		static auto ConsoleMessage = rc<bool(*)(uintptr_t, String)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("ConsoleMessage"), 1, _(""), _(""))));
		static auto ClientTick = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("ClientTick"), 0, _(""), _(""))));
		static auto SendProjectileUpdate = rc<void(*)(uintptr_t, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("SendProjectileUpdate"), 2, _(""), _(""))));
		static auto SendProjectileAttack = rc<void(*)(uintptr_t, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("SendProjectileAttack"), 2, _(""), _(""))));

		static auto GetMountVelocity = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetMountVelocity"), 0, _(""), _(""))));
		static auto InGesture = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("get_InGesture"), 0, _(""), _(""))));
		static auto IsOnATugboat = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("IsOnATugboat"), 0, _(""), _(""))));
		static auto isMounted = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("get_isMounted"), 0, _(""), _(""))));
		static auto InSafeZone = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("InSafeZone"), 0, _(""), _(""))));
	}
	namespace Component {
		static auto get_transform = rc<uintptr_t(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Component"), _("get_transform"), 0, _(""), _("UnityEngine"))));
	}
}
void _init_classes() {
	auto_co_ofsets::ItemModProjectile::GetRandomVelocity = rc<float(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("ItemModProjectile"), _("GetRandomVelocity"), 0, _(""), _(""))));
	auto_co_ofsets::Component::get_component = rc<uintptr_t(*)(uintptr_t, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Component"), _("GetComponent"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Component::gameObject = rc<uintptr_t(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Component"), _("get_gameObject"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::PlayerModel::RebuildAll = rc<void(*)()>(*rc<uintptr_t*>(il2cpp::method(_("PlayerModel"), _("RebuildAll"), 0, _(""), _(""))));
	auto_co_ofsets::Component::transform = rc<uintptr_t(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Component"), _("get_transform"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::BaseNetworkable::HasParent = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseNetworkable"), _("HasParent"), 0, _(""), _(""))));
	auto_co_ofsets::BaseNetworkable::get_ShortPrefabName = rc<String * (*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseNetworkable"), _("get_ShortPrefabName"), 0, _(""), _(""))));
	auto_co_ofsets::BuildingBlock::IsUpgradeBlocked = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BuildingBlock"), _("IsUpgradeBlocked"), 0, _(""), _(""))));
	auto_co_ofsets::BuildingBlock::CanAffordUpgrade = rc<bool(*)(uintptr_t, BuildingGrade::Enum, int, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BuildingBlock"), _("CanAffordUpgrade"), 3, _(""), _(""))));
	auto_co_ofsets::BuildingBlock::CanChangeToGrade = rc<bool(*)(uintptr_t, BuildingGrade::Enum, int, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BuildingBlock"), _("CanChangeToGrade"), 3, _(""), _(""))));
	auto_co_ofsets::BuildingBlock::UpgradeToGrade = rc<bool(*)(uintptr_t, BuildingGrade::Enum, int, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BuildingBlock"), _("UpgradeToGrade"), 3, _(""), _(""))));
	auto_co_ofsets::EnvironmentManager::Get = rc<uintptr_t(*)(Vector3, float)>(*rc<uintptr_t*>(il2cpp::method(_("EnvironmentManager"), _("Get"), 2, _(""), _(""))));
	auto_co_ofsets::Transform::position = rc<Vector3(*)(uintptr_t self)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("get_position"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Transform::get_localToWorldMatrix = rc<Matrix4x4(*)(uintptr_t self)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("get_localToWorldMatrix"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Transform::set_position = rc<void(*)(uintptr_t self, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("set_position"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Transform::get_localPosition = rc<Vector3(*)(uintptr_t self)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("get_localPosition"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Transform::set_localPosition = rc<void(*)(uintptr_t self, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("set_localPosition"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Transform::get_up = rc<Vector3(*)(uintptr_t self)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("get_up"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Transform::set_rotation = rc<void(*)(uintptr_t self, Vector4)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("set_rotation"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Transform::get_rotation = rc<Vector4(*)(uintptr_t self)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("get_rotation"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Transform::set_localScale = rc<void(*)(uintptr_t self, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("set_localScale"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Transform::InverseTransformPoint = rc<Vector3(*)(uintptr_t self, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("InverseTransformPoint"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Transform::InverseTransformDirection = rc<Vector3(*)(uintptr_t self, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("Transform"), _("InverseTransformDirection"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::HitInfo::PositionOnRay = rc<Vector3(*)(uintptr_t, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("HitInfo"), _("PositionOnRay"), 2, _(""), _(""))));
	auto_co_ofsets::HitInfo::LoadFromAttack = rc<void(*)(uintptr_t, uintptr_t, bool)>(*rc<uintptr_t*>(il2cpp::method(_("HitInfo"), _("LoadFromAttack"), 3, _(""), _(""))));
	//auto_co_ofsets::Material::getshader = rc<uintptr_t(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Material"), _("get_shader"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Renderer::get_material = rc<uintptr_t(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Renderer"), _("get_material"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Renderer::set_material = rc<void(*)(uintptr_t, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Renderer"), _("set_material"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::HitTest::BuildAttackMessage = rc<uintptr_t(*)(uintptr_t, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("HitTest"), _("BuildAttackMessage"), 2, _(""), _(""))));
	auto_co_ofsets::HitTest::HitPointWorld = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("HitTest"), _("HitPointWorld"), 0, _(""), _(""))));
	auto_co_ofsets::HitTest::HitNormalWorld = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("HitTest"), _("HitNormalWorld"), 0, _(""), _(""))));
	auto_co_ofsets::PlayerInventory::HasAmmo = rc<bool(*)(uintptr_t, AmmoTypes)>(*rc<uintptr_t*>(il2cpp::method(_("PlayerInventory"), _("HasAmmo"), 1, _(""), _(""))));
	auto_co_ofsets::Random::RandomRange = rc<float(*)(float min, float max)>(*rc<uintptr_t*>(il2cpp::method(_("Random"), _("RandomRange"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Mathx::Increment = rc<float(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Mathx"), _("Increment"), 1, _(""), _(""))));
	auto_co_ofsets::Mathx::Decrement = rc<float(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Mathx"), _("Decrement"), 1, _(""), _(""))));
	auto_co_ofsets::Mathx::Max = rc<float(*)(float f1, float f2, float f3)>(*rc<uintptr_t*>(il2cpp::method(_("Mathx"), _("Max"), 0, _(""), _(""))));
	auto_co_ofsets::Mathf::Abs = rc<float(*)(float x)>(*rc<uintptr_t*>(il2cpp::method(_("Mathf"), _("Abs"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Mathf::Sin = rc<float(*)(float f)>(*rc<uintptr_t*>(il2cpp::method(_("Mathf"), _("Sin"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Mathf::Cos = rc<float(*)(float f)>(*rc<uintptr_t*>(il2cpp::method(_("Mathf"), _("Cos"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Mathf::Tan = rc<float(*)(float f)>(*rc<uintptr_t*>(il2cpp::method(_("Mathf"), _("Tan"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Mathf::Atan2 = rc<float(*)(float y, float x)>(*rc<uintptr_t*>(il2cpp::method(_("Mathf"), _("Atan2"), 2, _(""), _("UnityEngine"))));
	auto_co_ofsets::Mathf::Clamp = rc<float(*)(float value, float min, float max)>(*rc<uintptr_t*>(il2cpp::method(_("Mathf"), _("Clamp"), 3, _(""), _("UnityEngine"))));
	auto_co_ofsets::Mathf::Sqrt = rc<float(*)(float f)>(*rc<uintptr_t*>(il2cpp::method(_("Mathf"), _("Sqrt"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Mathf::Lerp = rc<float(*)(float a, float b, float t)>(*rc<uintptr_t*>(il2cpp::method(_("Mathf"), _("Lerp"), 3, _(""), _("UnityEngine"))));
	auto_co_ofsets::MainCamera::get_position = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("MainCamera"), _("get_position"), 0, _(""), _(""))));
	auto_co_ofsets::MainCamera::get_rotation = rc<Quaternion(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("MainCamera"), _("get_rotation"), 0, _(""), _(""))));
	auto_co_ofsets::MainCamera::get_forward = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("MainCamera"), _("get_forward"), 0, _(""), _(""))));
	auto_co_ofsets::Time::time = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_time"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Time::deltaTime = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_deltaTime"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Time::fixedTime = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_fixedTime"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Time::unscaledTime = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_unscaledTime"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Time::unscaledDeltaTime = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_unscaledDeltaTime"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Time::fixedDeltaTime = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_fixedDeltaTime"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Time::maximumDeltaTime = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_maximumDeltaTime"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Time::smoothDeltaTime = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_smoothDeltaTime"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Time::timeScale = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_timeScale"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Time::frameCount = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_frameCount"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Time::renderedFrameCount = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_renderedFrameCount"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Time::realtimeSinceStartup = rc<float(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Time"), _("get_realtimeSinceStartup"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Material::getshader = rc<uintptr_t(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Material"), _("get_shader"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Material::set_shader = rc<void(*)(uintptr_t, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Material"), _("set_shader"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Material::get_name = rc<String * (*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Object"), _("get_name"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Material::SetInt = rc<void(*)(uintptr_t, String*, int)>(*rc<uintptr_t*>(il2cpp::method(_("Material"), _("SetInt"), 2, _(""), _("UnityEngine"))));
	auto_co_ofsets::Material::SetFloat = rc<void(*)(uintptr_t, String*, float)>(*rc<uintptr_t*>(il2cpp::method(_("Material"), _("SetFloat"), 2, _(""), _("UnityEngine"))));
	auto_co_ofsets::Material::set_renderQueue = rc<void(*)(uintptr_t, int)>(*rc<uintptr_t*>(il2cpp::method(_("Material"), _("set_renderQueue"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Material::SetColor = rc<void(*)(uintptr_t, String*, Color)>(*rc<uintptr_t*>(il2cpp::method(_("Material"), _("SetColor"), 2, _(""), _("UnityEngine"))));
	auto_co_ofsets::Networkable::get_components_in_children = rc<uintptr_t(*)(uintptr_t, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Component"), _("GetComponentsInChildren"), 0, _(""), _("UnityEngine"))));
}
void init_classes() {
	uintptr_t method_ptr = il2cpp::method(_("GamePhysics"), _("LineOfSight"), 4, _(""), _(""));
	if (!method_ptr) {
		return;
	}
	auto_co_ofsets::GamePhysics::LineOfSight = rc<bool(*)(Vector3 p0, Vector3 p1, int layerMask, uintptr_t ignoreEntity)>(*rc<uintptr_t*>(method_ptr));
	auto_co_ofsets::GamePhysics::LineOfSightRadius = rc<bool(*)(Vector3, Vector3, int, float, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("GamePhysics"), _("LineOfSightRadius"), 5, _(""), _(""))));
	auto_co_ofsets::GamePhysics::Trace = rc<bool(*)(Ray, float, RaycastHit, float, int, QueryTriggerInteraction, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("GamePhysics"), _("Trace"), 7, _(""), _(""))));
	auto_co_ofsets::Physics::Raycast = rc<bool(*)(Ray, RaycastHit, float, int, QueryTriggerInteraction)>(*rc<uintptr_t*>(il2cpp::method(_("Physics"), _("Raycast"), 5, _(""), _("UnityEngine"))));
	auto_co_ofsets::Physics::Raycast2 = rc<bool(*)(Vector3, Vector3, float, int, QueryTriggerInteraction)>(*rc<uintptr_t*>(il2cpp::method(_("Physics"), _("Raycast"), 5, _(""), _("UnityEngine"))));
	auto_co_ofsets::Physics::CheckCapsule = rc<bool(*)(Vector3, Vector3, float, int, QueryTriggerInteraction)>(*rc<uintptr_t*>(il2cpp::method(_("Physics"), _("CheckCapsule"), 5, _(""), _("UnityEngine"))));
	auto_co_ofsets::Physics::gravity = rc<Vector3(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Physics"), _("get_gravity"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Shader::Find = rc<uintptr_t(*)(String)>(*rc<uintptr_t*>(il2cpp::method(_("Shader"), _("Find"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Shader::get_passCount = rc<int(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Shader"), _("get_passCount"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::GameManifest::GUIDToObject = rc<uintptr_t(*)(String*)>(*rc<uintptr_t*>(il2cpp::method(_("GameManifest"), _("GUIDToObject"), 1, _(""), _(""))));
	auto_co_ofsets::GameObject::Internal_CreateGameObject = rc<void(*)(uintptr_t self, String shader)>(*rc<uintptr_t*>(il2cpp::method(_("GameObject"), _("Internal_CreateGameObject"), 2, _(""), _("UnityEngine"))));
	auto_co_ofsets::GameObject::GetComponent = rc<uintptr_t(*)(uintptr_t self, uintptr_t type)>(*rc<uintptr_t*>(il2cpp::method(_("GameObject"), _("GetComponent"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::GameObject::Internal_AddComponentWithType = rc<void(*)(uintptr_t self, uintptr_t componentType)>(*rc<uintptr_t*>(il2cpp::method(_("GameObject"), _("Internal_AddComponentWithType"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Object::DontDestroyOnLoad = rc<void(*)(uintptr_t target)>(*rc<uintptr_t*>(il2cpp::method(_("Object"), _("DontDestroyOnLoad"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Object::FindObjectFromInstanceID = rc<uintptr_t(*)(int instanceID)>(*rc<uintptr_t*>(il2cpp::method(_("Object"), _("FindObjectFromInstanceID"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Object::GetInstanceID = rc<int(*)(uintptr_t target)>(*rc<uintptr_t*>(il2cpp::method(_("Object"), _("GetInstanceID"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Event::get_current = rc<uintptr_t(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Event"), _("get_current"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Event::get_type = rc<EventType(*)(uintptr_t self)>(*rc<uintptr_t*>(il2cpp::method(_("Event"), _("get_type"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Event::get_keyCode = rc<KeyCode(*)(uintptr_t self)>(*rc<uintptr_t*>(il2cpp::method(_("Event"), _("get_keyCode"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::GUI::Label = rc<void(*)(Rect position, uintptr_t content, uintptr_t style)>(*rc<uintptr_t*>(il2cpp::method(_("GUI"), _("Label"), 3, _("content"), _("UnityEngine"), 2)));
	auto_co_ofsets::GUI::get_skin = rc<uintptr_t(*)()>(*rc<uintptr_t*>(il2cpp::method(_("GUI"), _("get_skin"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::GUI::set_color = rc<void(*)(Color color)>(*rc<DWORD64*>(il2cpp::method(_("GUI"), _("set_color"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::GUI::DrawTexture = rc<void (*)(Rect position, uintptr_t image, uintptr_t scaleMode, bool alphaBlend, float imageAspect, Color color, Vector4 borderWidths, Vector4 borderRadiuses, bool drawSmoothCorners)>(*rc<uintptr_t*>(il2cpp::method(_("GUI"), _("DrawTexture"), 9, _("image"), _("UnityEngine"), 2)));
	auto_co_ofsets::GUI::DrawTexture_min = rc<void (*)(Rect, uintptr_t)>(*rc<DWORD64*>(il2cpp::method(_("GUI"), _("DrawTexture"), 2, _("image"), _("UnityEngine"), 2)));
	auto_co_ofsets::AssetBundle::Unload = rc<void(*)(uintptr_t, bool)>(*rc<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("Unload"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::AssetBundle::LoadFromFile = rc<uintptr_t(*)(String path)>(*rc<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("LoadFromFile"), 1, _("path"), _("UnityEngine"), 1)));
	auto_co_ofsets::AssetBundle::LoadAsset_Internal = rc<uintptr_t(*)(uintptr_t self, String path, uintptr_t type)>(*rc<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("LoadAsset_Internal"), 2, _("name"), _("UnityEngine"), 1)));
	auto_co_ofsets::AssetBundle::LoadAsset = rc<uintptr_t(*)(uintptr_t bundle, String path, uintptr_t type)>(*rc<uintptr_t*>(il2cpp::method(_("AssetBundle"), _("LoadAsset"), 2, _("name"), _("UnityEngine"), 1)));
	//auto_co_ofsets::Networkable::get_components_in_children = rc<uintptr_t(*)(uintptr_t, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Component"), _("GetComponentsInChildren"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::GL::PushMatrix = rc<void(*)()>(*rc<DWORD64*>(il2cpp::method(_("GL"), _("PushMatrix"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::GL::MultMatrix = rc<void(*)(Matrix4x4Line)>(*rc<DWORD64*>(il2cpp::method(_("GL"), _("MultMatrix"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::GL::PopMatrix = rc<void(*)()>(*rc<DWORD64*>(il2cpp::method(_("GL"), _("PopMatrix"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::GL::Begin = rc<void(*)(int mode)>(*rc<uintptr_t*>(il2cpp::method(_("GL"), _("Begin"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::GL::Color_ = rc<void(*)(Color color)>(*rc<uintptr_t*>(il2cpp::method(_("GL"), _("Color"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::GL::Vertex = rc<void(*)(Vector3 v)>(*rc<uintptr_t*>(il2cpp::method(_("GL"), _("Vertex"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::GL::End = rc<void(*)()>(*rc<uintptr_t*>(il2cpp::method(_("GL"), _("End"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::GUIStyle::set_alignment = rc<void(*)(uintptr_t label, uintptr_t value)>(*rc<uintptr_t*>(il2cpp::method(_("GUIStyle"), _("set_alignment"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::GUIStyle::set_fontsize = rc<void(*)(uintptr_t label, int size)>(*rc<uintptr_t*>(il2cpp::method(_("GUIStyle"), _("set_fontSize"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::ItemDefinition::GetDisplayName = rc<uintptr_t(*)(uintptr_t self, uintptr_t item)>(*rc<uintptr_t*>(il2cpp::method(_("ItemDefinition"), _("GetDisplayName"), 1, _(""), _(""))));
	auto_co_ofsets::GUIContent::Temp = rc<uintptr_t(*)(String * t)>(*rc<uintptr_t*>(il2cpp::method(_("GUIContent"), _("Temp"), 1, _("t"), _("UnityEngine"), 1)));
	auto_co_ofsets::Input::GetMouseButton = rc<bool(*)(int button)>(*rc<uintptr_t*>(il2cpp::method(_("Input"), _("GetMouseButton"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Input::get_mousePosition = rc<Vector2(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Input"), _("get_mousePosition"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Input::GetAxis = rc<float(*)(String axisName)>(*rc<uintptr_t*>(il2cpp::method(_("Input"), _("GetAxis"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Input::GetKey = rc<bool(*)(KeyCode name)>(*rc<uintptr_t*>(il2cpp::method(_("Input"), _("GetKey"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Input::GetKeyInt = rc<bool(*)(KeyCode)>(*rc<uintptr_t*>(il2cpp::method(_("Input"), _("GetKeyInt"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Screen::get_height = rc<int(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Screen"), _("get_height"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Screen::get_width = rc<int(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Screen"), _("get_width"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::InputState::WasJustPressed = rc<bool(*)(uintptr_t, BUTTON)>(*rc<uintptr_t*>(il2cpp::method(_("InputState"), _("WasJustPressed"), 1, _(""), _(""))));
	auto_co_ofsets::BaseEntity::IsOutside = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("IsOutside"), 0, _(""), _(""))));
	auto_co_ofsets::BaseEntity::MaxVelocity = rc<float(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("MaxVelocity"), 0, _(""), _(""))));
	auto_co_ofsets::BaseEntity::GetParentVelocity = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("GetParentVelocity"), 0, _(""), _(""))));
	auto_co_ofsets::BaseEntity::BoundsPadding = rc<float(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("BoundsPadding"), 0, _(""), _(""))));
	auto_co_ofsets::BaseEntity::HasFlag = rc<bool(*)(uintptr_t, baseent_Flags)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("HasFlag"), 1, _(""), _(""))));
	auto_co_ofsets::BaseEntity::SendSignalBroadcast = rc<bool(*)(uintptr_t, Signal, String)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("SendSignalBroadcast"), 2, _(""), _(""))));
	auto_co_ofsets::BaseEntity::CenterPoint = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("CenterPoint"), 0, _(""), _(""))));
	auto_co_ofsets::BaseEntity::GetWorldVelocity = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("GetWorldVelocity"), 0, _(""), _(""))));
	auto_co_ofsets::BaseEntity::Distance = rc<float(*)(uintptr_t, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("Distance"), 2, _(""), _(""))));
	auto_co_ofsets::BaseEntity::ServerRPC = rc<void(*)(uintptr_t, String)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("ServerRPC"), 1, _("funcName"), _(""), 1)));
	auto_co_ofsets::BaseEntity::ServerRPC4 = rc<void(*)(uintptr_t, String, Vector3, Vector3, bool)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("ServerRPC"), 4, _("funcName"), _(""), 1)));
	auto_co_ofsets::Rigidbody::get_velocity = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Rigidbody"), _("get_velocity"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Rigidbody::set_velocity = rc<void(*)(uintptr_t, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("Rigidbody"), _("set_velocity"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::AimConeUtil::GetModifiedAimConeDirection = rc<Vector3(*)(float, Vector3, bool)>(*rc<uintptr_t*>(il2cpp::method(_("AimConeUtil"), _("GetModifiedAimConeDirection"), 3, _(""), _(""))));
	auto_co_ofsets::Texture2D::get_whiteTexture = rc<uintptr_t(*)()>(*rc<uintptr_t*>(il2cpp::method(_("Texture2D"), _("get_whiteTexture"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::Texture2D::SetPixel = rc<void(*)(uintptr_t target, int x, int y, Color color)>(*rc<uintptr_t*>(il2cpp::method(_("Texture2D"), _("SetPixel"), 3, _(""), _("UnityEngine"))));
	auto_co_ofsets::Texture2D::Apply = rc<void(*)(uintptr_t target, bool updateMipmaps)>(*rc<uintptr_t*>(il2cpp::method(_("Texture2D"), _("Apply"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Texture2D::Internal_Create = rc<void(*)(uintptr_t mono, int w, int h, int mipCount, int format, int colorSpace, int flags, __int64 nativeTex, String mipmapLimitGroupName)>(*rc<uintptr_t*>(il2cpp::method(_("Texture2D"), _("Internal_Create"), 9, _(""), _("UnityEngine"))));
	auto_co_ofsets::Texture2D::get_isReadable = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Texture2D"), _("get_isReadable"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::DamageTypeList::Scale = rc<void(*)(uintptr_t, DamageType, bool)>(*rc<uintptr_t*>(il2cpp::method(_("DamageTypeList"), _("Scale"), 2, _(""), _("Rust"))));
	auto_co_ofsets::DamageTypeList::Total = rc<float(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("DamageTypeList"), _("Total"), 0, _(""), _("Rust"))));
	auto_co_ofsets::BaseMovement::get_TargetMovement = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseMovement"), _("get_TargetMovement"), 0, _(""), _(""))));
	auto_co_ofsets::BaseMovement::set_TargetMovement = rc<void(*)(uintptr_t, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("BaseMovement"), _("set_TargetMovement"), 1, _(""), _(""))));
	auto_co_ofsets::BaseMovement::TeleportTo = rc<void(*)(uintptr_t, Vector3, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseMovement"), _("TeleportTo"), 2, _(""), _(""))));

	auto_co_ofsets::TerrainHeightMap::GetNormal = rc<Vector3(*)(uintptr_t, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("TerrainHeightMap"), _("GetNormal"), 0, _(""), _(""))));
	auto_co_ofsets::TerrainHeightMap::GetHeight = rc<float(*)(uintptr_t, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("TerrainHeightMap"), _("GetHeight"), 0, _(""), _(""))));
	auto_co_ofsets::Terrain::SampleHeight = rc<float(*)(uintptr_t, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("Terrain"), _("SampleHeight"), 1, _("worldPosition"), _("UnityEngine"), 1)));
	auto_co_ofsets::TerrainCollision::GetIgnore = rc<bool(*)(uintptr_t, Vector3, float)>(*rc<uintptr_t*>(il2cpp::method(_("TerrainCollision"), _("GetIgnore"), 2, _(""), _(""))));
	auto_co_ofsets::TerrainMeta::get_Position = rc<Vector3(*)(DWORD64)>(*rc<uintptr_t*>(il2cpp::method(_("TerrainMeta"), _("get_Position"), 0, _(""), _(""))));
	auto_co_ofsets::TerrainMeta::get_HeightMap = rc<uintptr_t(*)(DWORD64)>(*rc<uintptr_t*>(il2cpp::method(_("TerrainMeta"), _("get_HeightMap"), 0, _(""), _(""))));
	auto_co_ofsets::TerrainMeta::get_Terrain = rc<uintptr_t(*)(DWORD64)>(*rc<uintptr_t*>(il2cpp::method(_("TerrainMeta"), _("get_Terrain"), 0, _(""), _(""))));
	auto_co_ofsets::TerrainMeta::get_Collision = rc<uintptr_t(*)(DWORD64)>(*rc<uintptr_t*>(il2cpp::method(_("TerrainMeta"), _("get_Collision"), 0, _(""), _(""))));
	auto_co_ofsets::GameTrace::TraceAll = rc<bool(*)(uintptr_t, uintptr_t, int)>(*rc<uintptr_t*>(il2cpp::method(_("GameTrace"), _("TraceAll"), 3, _(""), _(""))));
	auto_co_ofsets::DDraw::Text = rc<void(*)(String*, Vector3, Color, float, float, bool)>(*rc<uintptr_t*>(il2cpp::method(_("DDraw"), _("Text"), 6, _(""), _("UnityEngine"))));
	auto_co_ofsets::DDraw::Line = rc<void(*)(Vector3, Vector3, Color, float, bool, bool)>(*rc<uintptr_t*>(il2cpp::method(_("DDraw"), _("Line"), 6, _(""), _("UnityEngine"))));
	auto_co_ofsets::DDraw::Capsule = rc<void(*)(Vector3, Quaternion, float, float, Color, float, bool, bool)>(*rc<uintptr_t*>(il2cpp::method(_("DDraw"), _("Capsule"), 8, _(""), _("UnityEngine"))));
	auto_co_ofsets::DDraw::Sphere = rc<void(*)(Vector3, float, Color, float, bool, bool)>(*rc<uintptr_t*>(il2cpp::method(_("DDraw"), _("Sphere"), 6, _(""), _("UnityEngine"))));
	auto_co_ofsets::AssetNameCache::GetName = rc<String * (*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("AssetNameCache"), _("GetName"), 1, _(""), _(""))));
	auto_co_ofsets::Projectile::get_isAuthoritative = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Projectile"), _("get_isAuthoritative"), 0, _(""), _(""))));
	auto_co_ofsets::Projectile::get_isAlive = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Projectile"), _("get_isAlive"), 0, _(""), _(""))));
	auto_co_ofsets::Projectile::DoHit = rc<bool(*)(uintptr_t, uintptr_t, Vector3, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("Projectile"), _("DoHit"), 3, _(""), _(""))));
	auto_co_ofsets::Projectile::Launch = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Projectile"), _("Launch"), 0, _(""), _(""))));
	auto_co_ofsets::Projectile::SetEffectScale = rc<void(*)(uintptr_t, float)>(*rc<uintptr_t*>(il2cpp::method(_("Projectile"), _("SetEffectScale"), 1, _(""), _(""))));
	auto_co_ofsets::Projectile::UpdateVelocity = rc<void(*)(uintptr_t, float)>(*rc<uintptr_t*>(il2cpp::method(_("Projectile"), _("UpdateVelocity"), 1, _(""), _(""))));
	auto_co_ofsets::Projectile::Retire = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Projectile"), _("Retire"), 0, _(""), _(""))));
	auto_co_ofsets::Projectile::CalculateEffectScale = rc<float(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Projectile"), _("CalculateEffectScale"), 0, _(""), _(""))));
	auto_co_ofsets::Projectile::DoFlybySound = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Projectile"), _("DoFlybySound"), 0, _(""), _(""))));
	auto_co_ofsets::Projectile::get_transform = rc<uintptr_t(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Component"), _("get_transform"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::ItemIcon::RunTimedAction = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("ItemIcon"), _("RunTimedAction"), 0, _(""), _(""))));
	auto_co_ofsets::PlayerWalkMovement::Jump = rc<void(*)(uintptr_t, uintptr_t, bool)>(*rc<uintptr_t*>(il2cpp::method(_("PlayerWalkMovement"), _("Jump"), 2, _(""), _(""))));
	auto_co_ofsets::SkinnedMultiMesh::get_Renderers = rc<List<Renderer_*>*(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("SkinnedMultiMesh"), _("get_Renderers"), 0, _(""), _(""))));
	auto_co_ofsets::ModelState::set_ducked = rc<void(*)(uintptr_t, bool)>(*rc<uintptr_t*>(il2cpp::method(_("ModelState"), _("set_ducked"), 1, _(""), _(""))));
	auto_co_ofsets::ModelState::set_jumped = rc<void(*)(uintptr_t, bool)>(*rc<uintptr_t*>(il2cpp::method(_("ModelState"), _("set_jumped"), 1, _(""), _(""))));
	auto_co_ofsets::HeldEntity::GetFovOverride = rc<float(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("HeldEntity"), _("GetFovOverride"), 0, _(""), _(""))));
	
	// MetalDetectorSource не существует в текущей версии игры - закомментировано
	// auto_co_ofsets::MetalDetectorSource::get_SpawnLocations = rc<List<Vector3>*(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("MetalDetectorSource"), _("get_SpawnLocations"), 0, _(""), _(""))));
	
	auto_co_ofsets::AttackEntity::CalculateCooldownTime = rc<float(*)(uintptr_t, float, float, bool)>(*rc<uintptr_t*>(il2cpp::method(_("AttackEntity"), _("CalculateCooldownTime"), 3, _(""), _(""))));
	auto_co_ofsets::AttackEntity::StartAttackCooldown = rc<void(*)(uintptr_t, float)>(*rc<uintptr_t*>(il2cpp::method(_("AttackEntity"), _("StartAttackCooldown"), 1, _(""), _(""))));
	auto_co_ofsets::AttackEntity::GetInheritedVelocity = rc<Vector3(*)(uintptr_t, uintptr_t, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("AttackEntity"), _("GetInheritedVelocity"), 2, _(""), _(""))));
	auto_co_ofsets::AttackEntity::HasAttackCooldown = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("AttackEntity"), _("HasAttackCooldown"), 0, _(""), _(""))));
	auto_co_ofsets::AttackEntity::GetAttackCooldown = rc<float(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("AttackEntity"), _("GetAttackCooldown"), 0, _(""), _(""))));
	auto_co_ofsets::BaseProjectile::LaunchProjectile = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("LaunchProjectile"), 0, _(""), _(""))));
	auto_co_ofsets::BaseProjectile::GetProjectileVelocityScale = rc<float(*)(uintptr_t, bool)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("GetProjectileVelocityScale"), 1, _(""), _(""))));
	auto_co_ofsets::BaseProjectile::IsSilenced = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("IsSilenced"), 0, _(""), _(""))));
	auto_co_ofsets::BaseProjectile::ShotFired = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("ShotFired"), 0, _(""), _(""))));
	auto_co_ofsets::BaseProjectile::BeginCycle = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("BeginCycle"), 0, _(""), _(""))));
	auto_co_ofsets::BaseProjectile::DoAttack = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("DoAttack"), 0, _(""), _(""))));
	auto_co_ofsets::BaseProjectile::UpdateAmmoDisplay = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("UpdateAmmoDisplay"), 0, _(""), _(""))));
	auto_co_ofsets::BaseProjectile::DidAttackClientside = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("DidAttackClientside"), 0, _(""), _(""))));
	auto_co_ofsets::BaseProjectile::StartReloadCooldown = rc<void(*)(uintptr_t, float)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("StartReloadCooldown"), 1, _(""), _(""))));
	auto_co_ofsets::BaseProjectile::GetReloadDuration = rc<float(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("GetReloadDuration"), 0, _(""), _(""))));
	auto_co_ofsets::BaseProjectile::GetAvailableAmmo = rc<int(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseProjectile"), _("GetAvailableAmmo"), 0, _(""), _(""))));
	auto_co_ofsets::Sprite::get_texture = rc<uintptr_t(*)(DWORD64)>(*rc<uintptr_t*>(il2cpp::method(_("Sprite"), _("get_texture"), 0, _(""), _("UnityEngine"))));
	auto_co_ofsets::RenderSettings::set_ambientMode = rc<void(*)(AmbientMode)>(*rc<uintptr_t*>(il2cpp::method(_("RenderSettings"), _("set_ambientMode"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::RenderSettings::set_ambientIntensity = rc<void(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("RenderSettings"), _("set_ambientIntensity"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::RenderSettings::set_ambientLight = rc<void(*)(Color)>(*rc<uintptr_t*>(il2cpp::method(_("RenderSettings"), _("set_ambientLight"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::RenderSettings::set_skybox = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("RenderSettings"), _("set_skybox"), 1, _(""), _("UnityEngine"))));
	auto_co_ofsets::Weather::set_atmosphere_rayleigh = rc<void(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Weather"), _("set_atmosphere_rayleigh"), 1, _(""), _("ConVar"))));
	auto_co_ofsets::Weather::set_atmosphere_mie = rc<void(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Weather"), _("set_atmosphere_mie"), 1, _(""), _("ConVar"))));
	auto_co_ofsets::Weather::set_atmosphere_brightness = rc<void(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Weather"), _("set_atmosphere_brightness"), 1, _(""), _("ConVar"))));
	auto_co_ofsets::Weather::set_cloud_opacity = rc<void(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Weather"), _("set_cloud_opacity"), 1, _(""), _("ConVar"))));
	auto_co_ofsets::Weather::set_atmosphere_contrast = rc<void(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Weather"), _("set_atmosphere_contrast"), 1, _(""), _("ConVar"))));
	auto_co_ofsets::Weather::set_fog = rc<void(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Weather"), _("set_fog"), 1, _(""), _("ConVar"))));
	auto_co_ofsets::Weather::set_rain = rc<void(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Weather"), _("set_rain"), 1, _(""), _("ConVar"))));
	auto_co_ofsets::Weather::set_thunder = rc<void(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Weather"), _("set_thunder"), 1, _(""), _("ConVar"))));
	auto_co_ofsets::Weather::set_wind = rc<void(*)(float)>(*rc<uintptr_t*>(il2cpp::method(_("Weather"), _("set_wind"), 1, _(""), _("ConVar"))));
	auto_co_ofsets::Item::get_isBroken = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Item"), _("get_isBroken"), 0, _(""), _(""))));
	auto_co_ofsets::Item::get_iconSprite = rc<DWORD64(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Item"), _("get_iconSprite"), 0, _(""), _(""))));
	auto_co_ofsets::PlayerEyes::get_position = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("PlayerEyes"), _("get_position"), 0, _(""), _(""))));
	auto_co_ofsets::PlayerEyes::get_center = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("PlayerEyes"), _("get_center"), 0, _(""), _(""))));
	auto_co_ofsets::PlayerEyes::BodyForward = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("PlayerEyes"), _("BodyForward"), 0, _(""), _(""))));
	auto_co_ofsets::PlayerEyes::get_rotation = rc<Quaternion(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("PlayerEyes"), _("get_rotation"), 0, _(""), _(""))));
	auto_co_ofsets::BaseViewModel::get_activemodel = rc<uintptr_t(*)()>(*rc<uintptr_t*>(il2cpp::method(_("BaseViewModel"), _("get_ActiveModel"), 0, _(""), _(""))));
	auto_co_ofsets::LocalPlayer::ItemCommand = rc<void(*)(unsigned int, String)>(*rc<uintptr_t*>(il2cpp::method(_("LocalPlayer"), _("ItemCommand"), 2, _(""), _(""))));
	auto_co_ofsets::RandomUsernames::Get1 = rc<String * (*)(uintptr_t, int)>(*rc<uintptr_t*>(il2cpp::method(_("RandomUsernames"), _("Get"), 1, _(""), _("Facepunch"))));
	auto_co_ofsets::RandomUsernames::Get2 = rc<String * (*)(uintptr_t, uint64_t)>(*rc<uintptr_t*>(il2cpp::method(_("RandomUsernames"), _("Get"), 1, _(""), _("Facepunch"))));
	auto_co_ofsets::SteamPlatform::get_UserName = rc<String * (*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("SteamPlatform"), _("get_UserName"), 0, _(""), _("Rust.Platform.Steam"))));
	auto_co_ofsets::SteamPlatform::set_UserName = rc<void(*)(uintptr_t, String*)>(*rc<uintptr_t*>(il2cpp::method(_("SteamPlatform"), _("set_UserName"), 1, _(""), _("Rust.Platform.Steam"))));
	auto_co_ofsets::StashContainer::IsHidden = rc<bool(*)()>(*rc<uintptr_t*>(il2cpp::method(_("StashContainer"), _("IsHidden"), 0, _(""), _(""))));
	auto_co_ofsets::BaseMelee::get_CanAttack = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseMelee"), _("get_CanAttack"), 0, _(""), _(""))));
	auto_co_ofsets::BaseMelee::get_CanThrow = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseMelee"), _("get_CanThrow"), 0, _(""), _(""))));
	auto_co_ofsets::BaseMelee::DoAttack = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseMelee"), _("DoAttack"), 0, _(""), _(""))));
	auto_co_ofsets::BaseMelee::DoThrow = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseMelee"), _("DoThrow"), 0, _(""), _(""))));
	auto_co_ofsets::BaseMelee::ProcessAttack = rc<void(*)(uintptr_t, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseMelee"), _("ProcessAttack"), 1, _(""), _(""))));
	auto_co_ofsets::WaterLevel::Test = rc<bool(*)(Vector3, bool, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("WaterLevel"), _("Test"), 3, _(""), _(""))));
	auto_co_ofsets::WaterLevel::GetWaterDepth = rc<float(*)(Vector3, bool, bool, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("WaterLevel"), _("GetWaterDepth"), 4, _(""), _(""))));
	auto_co_ofsets::BasePlayer::ScaleDamage = rc<void(*)(uintptr_t, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("ScaleDamage"), 1, _(""), _(""))));
	auto_co_ofsets::BasePlayer::IsRunning = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("IsRunning"), 0, _(""), _(""))));
	auto_co_ofsets::BasePlayer::IsDucked = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("IsDucked"), 0, _(""), _(""))));
	auto_co_ofsets::BasePlayer::IsSwimming = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("IsSwimming"), 0, _(""), _(""))));
	auto_co_ofsets::BasePlayer::IsCrawling = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("IsCrawling"), 0, _(""), _(""))));
	auto_co_ofsets::BasePlayer::GetSpeed = rc<float(*)(uintptr_t, float, float, float)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetSpeed"), 3, _(""), _(""))));
	auto_co_ofsets::BasePlayer::OnLand = rc<void(*)(uintptr_t, float)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("OnLand"), 1, _("fVelocity"), _(""), 1)));
	auto_co_ofsets::BasePlayer::GetMounted = rc<DWORD64(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetMounted"), 0, _(""), _(""))));
	auto_co_ofsets::BasePlayer::ForcePositionTo = rc<void(*)(uintptr_t, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("ForcePositionTo"), 0, _(""), _(""))));
	auto_co_ofsets::BasePlayer::WorldSpaceBounds = rc<OBB(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("WorldSpaceBounds"), 0, _(""), _(""))));
	auto_co_ofsets::BasePlayer::ClosestPoint = rc<Vector3(*)(uintptr_t, Vector3)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("ClosestPoint"), 2, _(""), _(""))));
	auto_co_ofsets::BasePlayer::PivotPoint = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("PivotPoint"), 0, _(""), _(""))));
	auto_co_ofsets::BasePlayer::GetMaxSpeed = rc<float(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetMaxSpeed"), 0, _(""), _(""))));
	auto_co_ofsets::BasePlayer::GetHeight = rc<float(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetHeight"), 0, _(""), _(""))));
	auto_co_ofsets::BasePlayer::GetHeldItem = rc<uintptr_t(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetHeldItem"), 0, _(""), _(""))));
	auto_co_ofsets::BasePlayer::NewProjectileID = rc<int(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("NewProjectileID"), 0, _(""), _(""))));
	auto_co_ofsets::BasePlayer::NewProjectileSeed = rc<int(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("NewProjectileSeed"), 0, _(""), _(""))));
	auto_co_ofsets::BasePlayer::OnLadder = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("OnLadder"), 0, _(""), _(""))));
	auto_co_ofsets::BasePlayer::ConsoleMessage = rc<bool(*)(uintptr_t, String)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("ConsoleMessage"), 1, _(""), _(""))));
	auto_co_ofsets::BasePlayer::ClientTick = rc<void(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("ClientTick"), 0, _(""), _(""))));
	auto_co_ofsets::BasePlayer::SendProjectileUpdate = rc<void(*)(uintptr_t, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("SendProjectileUpdate"), 2, _(""), _(""))));
	auto_co_ofsets::BasePlayer::SendProjectileAttack = rc<void(*)(uintptr_t, uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("SendProjectileAttack"), 2, _(""), _(""))));

	auto_co_ofsets::BasePlayer::GetMountVelocity = rc<Vector3(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("GetMountVelocity"), 0, _(""), _(""))));
	auto_co_ofsets::BasePlayer::InGesture = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("get_InGesture"), 0, _(""), _(""))));
	
	// IsOnATugboat не существует в текущей версии игры - закомментировано
	// auto_co_ofsets::BasePlayer::IsOnATugboat = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("IsOnATugboat"), 0, _(""), _(""))));
	
	auto_co_ofsets::BasePlayer::isMounted = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("get_isMounted"), 0, _(""), _(""))));
	auto_co_ofsets::BasePlayer::InSafeZone = rc<bool(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("InSafeZone"), 0, _(""), _(""))));
	auto_co_ofsets::String_::Contains = rc<bool(*)(String*, String*)>(*rc<uintptr_t*>(il2cpp::method(_("String"), _("Contains"), 1, _(""), _("System"))));
	auto_co_ofsets::Component::get_transform = rc<uintptr_t(*)(uintptr_t)>(*rc<uintptr_t*>(il2cpp::method(_("Component"), _("get_transform"), 0, _(""), _("UnityEngine"))));
}