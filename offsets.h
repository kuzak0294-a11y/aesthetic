namespace CO
{
    //dump.cs
    constexpr auto CursorManagerUpdate = 0x910C10; // public class CursorManager -> private void Update() { }
    constexpr auto LineOfSight = 0x6D2A40; // public static bool LineOfSight(Vector3 p0, Vector3 p1, int layerMask, BaseEntity ignoreEntity) { }
    constexpr auto RaycastHit = 0x25ABE90; // public static bool Raycast(Vector3 origin, Vector3 direction, out RaycastHit hitInfo, float maxDistance, int layerMask, QueryTriggerInteraction queryTriggerInteraction) { }

    constexpr auto GetGameObjectComponent = 0x25477E0; // public sealed class GameObject -> public Component GetComponent(Type type) { }
}